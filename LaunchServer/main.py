from flask import Flask, request, send_file
import json
import sqlite3
import uuid
import os
import hashlib
import random
import shutil
import time
import base64

conn = sqlite3.connect("data.db", check_same_thread=False)
cur = conn.cursor()
cur.execute("""CREATE TABLE IF NOT EXISTS users(
   uuid TEXT PRIMARY KEY,
   username TEXT,
   password TEXT,
   accessToken TEXT,
   serverId TEXT);
""")
cur.execute("""CREATE TABLE IF NOT EXISTS servers(
   id INT PRIMARY KEY,
   name TEXT,
   description TEXT,
   img TEXT,
   path TEXT,
   version TEXT,
   modloader TEXT);
""")
cur.execute("""CREATE TABLE IF NOT EXISTS filewl(
    id INT,
    path TEXT PRIMARY KEY);
""")

# cur.execute("DROP TABLE users;")
# conn.commit()
# cur.execute("DROP TABLE servers;")
# conn.commit()
# cur.execute("DROP TABLE filewl;")
# conn.commit()

app = Flask(__name__)

def getdir(dir_path):
    file_list = []
    fs = os.listdir(dir_path)
    for f in fs:
        if os.path.isfile(dir_path+"/"+f):
            file_list.append({"link": dir_path.replace("/", "&"), "name": f, "path": dir_path, "hash": hashlib.md5(open(dir_path+"/"+f, 'rb').read()).hexdigest()})
        else:
            file_list.extend(getdir(dir_path+"/"+f))
    return file_list

def getSkinURL(username, type):
    texture = "textures/" + type + "/" + username.lower() + ".jpg"
    if (os.path.exists(texture)):
        skin = "skins/" + str(hashlib.md5(texture).hexdigest()) + '.png'
        if (os.path.exists(skin)):
            shutil.copy(texture, skin)
            return "http://192.168.100.117/file/path=skins&" + str(hashlib.md5(texture).hexdigest()) + ".png"
    else:
        return False


def getProfile(uuid, username):
    textures = {}
    if (getSkinURL(username, 'skin')):
        textures['SKIN'] = getSkinURL(username, 'skin')
    if (getSkinURL(username, 'cape')):
        textures['CAPE'] = getSkinURL(username, 'cape')
    property = {'timestamp': time.time(), 'profileId': uuid, 'profileName': username, 'textures': textures}
    profile = {'id': uuid, 'name': username, 'properties': [{'name': 'textures', 'value': str(base64.b64encode(json.dumps(property).encode('utf-8')).decode('utf-8')), 'signature': ''}]}
    return profile

@app.route('/addwlfile', methods=['POST'])
def addwlfile():
    data = request.get_json()
    try:
        cur.execute(f"INSERT INTO filewl(id, path) VALUES({data['id']}, '{data['path']}');")
        conn.commit()
    except:
        return "400"
    return "200"

@app.route('/filewl/id=<int:id>', methods=['GET'])
def filewl(id):
    cur.execute(f"SELECT path FROM filewl WHERE id == {id};")
    data = cur.fetchall()
    file_list = []
    for file in data:
        file_list.append(file[0])
    if len(data) == 0:
        return "404"
    else:
        return json.dumps(file_list)


@app.route('/addserver', methods=['POST'])
def addserver():
    data = request.get_json()
    cur.execute("SELECT id FROM servers;")
    ids = cur.fetchall()
    if len(ids) == 0:
        id = 0
    else:
        id = ids[-1][0]+1
    cur.execute(
        f"INSERT INTO servers(id, name, description, img, path, version, modloader) VALUES({id}, '{data['name']}', '{data['description']}', '{data['img']}', '{data['path']}', '{data['version']}', '{data['modloader']}');")
    conn.commit()
    return "200"

@app.route('/serverfiles/id=<int:id>', methods=['GET'])
def serverfiles(id):
    cur.execute(f"SELECT path FROM servers WHERE id == {id};")
    data = cur.fetchall()
    if len(data) == 0:
        return "404"
    else:
        return json.dumps(getdir(data[0][0]))

@app.route('/server/id=<int:id>', methods=['GET'])
def server(id):
    cur.execute(f"SELECT name, description, img, path, version, modloader FROM servers WHERE id == {id};")
    data = cur.fetchall()
    if len(data) == 0:
        return "404"
    else:
        return json.dumps({"name": data[0][0], "description": data[0][1], "img": data[0][2], "path": data[0][3], "version": data[0][4], "modloader": data[0][5]})

@app.route('/file/path=<string:path>', methods=['GET'])
def file(path):
    path = path.replace("&", "/")
    return send_file(path)

@app.route('/login/nickname=<string:nickname>&password=<string:password>', methods=['GET'])
def login(nickname, password):
    cur.execute("SELECT username FROM users;")
    names = cur.fetchall()
    for name in names:
        if nickname == name[0]:
            cur.execute(f"SELECT password, uuid, accessToken FROM users WHERE username == '{nickname}';")
            data = cur.fetchall()
            if data[0][0] == password:
                accessToken = hashlib.md5(str(random.randint(1000000000, 2147483647)).encode("utf-8") + str(random.randint(1000000000, 2147483647)).encode("utf-8")).hexdigest()
                cur.execute(f"UPDATE users SET accessToken = '{accessToken}' WHERE username == '{nickname}';")
                conn.commit()
                return json.dumps({"uuid": data[0][1], "accessToken": str(accessToken)})
            else:
                return "400"
    else:
        return "404"

@app.route('/register/nickname=<string:nickname>&password=<string:password>', methods=['GET'])
def register(nickname, password):
    cur.execute("SELECT username FROM users;")
    names = cur.fetchall()
    for name in names:
        if nickname == name[0]:
            return "400"
    else:
        cur.execute(
            f"INSERT INTO users(uuid, username, password, accessToken, serverId) VALUES('{uuid.uuid4()}', '{nickname}', '{password}', '', '');")
        conn.commit()
        return "200"

@app.route('/auth/join', methods=['POST'])
def auth_join():
    data = request.get_json()
    uuid = data['selectedProfile'][:8] + "-" + data['selectedProfile'][8:]
    uuid = uuid[:13] + "-" + uuid[13:]
    uuid = uuid[:18] + "-" + uuid[18:]
    uuid = uuid[:23] + "-" + uuid[23:]
    cur.execute(f"SELECT uuid FROM users WHERE uuid == '{uuid}' AND accessToken == '{data['accessToken']}';")
    sqldata = cur.fetchall()
    if len(sqldata) > 0:
        cur.execute(f"UPDATE users SET serverId = '{data['serverId']}' WHERE uuid == '{uuid}';")
        conn.commit()
        return '', 204
    else:
        return json.dumps({"error": 'ForbiddenOperationException', "errorMessage": 'Invalid username or password', "cause": ''})

@app.route('/auth/hasJoined', methods=['GET'])
def auth_hasjoined():
    serverId = request.args.get('serverId')
    username = request.args.get('username')
    cur.execute(f"SELECT uuid FROM users WHERE username == '{username}' and serverId == '{serverId}';")
    data = cur.fetchall()
    if len(data) > 0:
        return json.dumps(getProfile(data[0][0], username))
    else:
        return "400"

@app.route('/auth/profile', methods=['GET'])
def auth_profile():
    uuid = request.args.get('uuid')
    uuid = uuid[:8] + "-" + uuid[8:]
    uuid = uuid[:13] + "-" + uuid[13:]
    uuid = uuid[:18] + "-" + uuid[18:]
    uuid = uuid[:23] + "-" + uuid[23:]
    cur.execute(f"SELECT username FROM users WHERE uuid = '{uuid}';")
    data = cur.fetchall()
    return json.dumps(getProfile(uuid, data[0][0]))

app.run(host="192.168.100.117", port=5000)