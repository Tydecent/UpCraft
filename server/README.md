# UpCraft Server

UpCraft 的服务端。

## 简介
这是UpCraft的服务端，负责管理软件的版本信息，并提供给客户端软件更新和版本信息。

# 配置文件
`config.json`是服务端的配置文件，应当放置在服务端的根目录下。

配置文件示例：
```json
{
    "latest_version" : "1.0.0",
    "package_patg" : "./Update_Package/",
    "port" : 5000
}
```
其中：
|键|值|
|-|-|
|`latest_version`|最新版本号|
|`package_patg`|更新包存放路径|
|`port`|服务端监听端口|

## 启动

### 创建虚拟环境（可选）
> [!TIP]
> 我们强烈推荐您使用虚拟环境来管理Python依赖。

**Linux/MacOS：**
```bash
python3 -m venv venv
source myenv/bin/activate
```
**Windows：**
```powershell
python -m venv venv
.\venv\Scripts\Activate.ps1
```

### 安装依赖
```bash
pip install -r requirements.txt
```

### 启动服务
```bash
python server.py
```

## API文档
详细的API文档见[服务端API文档](../docs/server_api.md)。