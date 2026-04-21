import json
import threading
import time
from flask import Flask, jsonify, send_file


CONFIG_FILE = "config.json"
VERSION = None
PACKAGE_FILE = None

def update_version_file():
    """
    定时读取文件

    该函数在单独线程运行，每隔10秒读取一次version.json文件，并更新全局变量VERSION。
    """
    global VERSION
    global PACKAGE_FILE

    while True:
        with open(CONFIG_FILE, "r") as f:
            data = json.load(f)
            VERSION = data["version"]
            PACKAGE_FILE = data["package_file"]
        time.sleep(10)

update_version_file_thread = threading.Thread(target=update_version_file)
update_version_file_thread.start()


app = Flask(__name__)

@app.route("/health", methods=["GET"])
def health():
    return jsonify({"status": "ok"}), 200

@app.route("/api/v1/get_version", methods=["GET"])
def get_version():
    return jsonify({"version": VERSION}), 200

@app.route("/api/v1/download_package", methods=["GET"])
def download_package():
    """
    下载更新
    向客户端返回包文件。
    """
    global PACKAGE_FILE

    return send_file(PACKAGE_FILE, as_attachment=True), 200


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)