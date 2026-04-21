# UpCraft 客户端头文件

UpCraft 客户端头文件位于`client/include/upcraft.hpp`，包含了客户端与服务端通信的核心逻辑。

## 依赖项
- **nlohmann/json**：用于解析 JSON 格式的响应数据。
- **cpp-httplib**：用于发送 HTTP 请求（GET 方法）。

## 命名空间
所有代码均位于`UpCraft`命名空间中

## 类：`UpCraft`
### 构造函数
```cpp
UpCraft(const std::string& url);
```
**参数：**
- `url`：远程服务器的基本URL。该URL会用于后续所有请求的拼接。

> [!IMPORTANT]  
> 目前仅支持http协议，不支持https。

### 成员函数
#### 1. `health()`
```cpp
int health();
```
**描述：**
向服务器发送`GET /health`请求，检查服务是否可用，

**返回值**
- `0`：服务健康，HTTP 响应状态码为 200。
- 若非零，则为实际 HTTP 响应状态码。

#### 2. `get_version()`
```cpp
std::string get_version();
```
**描述：**
向服务器发送`GET /version`请求，获取当前可用的最新版本号。

**返回值**
- 若请求成功，则返回最新版本号。
- 若请求失败，则返回`unknown`。

#### 3. `download_update()`
```cpp
int download_update();
```
**描述：**
向服务器发送`GET /update`请求，下载最新版本的客户端。

**返回值**
- `0`：下载成功。
- 若非零，则为实际 HTTP 响应状态码。