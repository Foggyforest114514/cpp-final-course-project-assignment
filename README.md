# 扫雷（Saolei）——C++ / EasyX 项目

## 简介
- 本项目为一个基于 EasyX 的简单扫雷小游戏（Windows）。
- 使用 C++14 编写，配套 UI 与鼠标消息处理，适合作为课程项目或示例代码学习。

## 主要文件
- `saolei.cpp`：程序入口（`main`）。
- `GameFrame.h` / `GameFrame.cpp`：游戏主框架、事件循环、绘制与逻辑。
- `Item.h` / `Item.cpp`：格子（方块）类（图像与状态）。
- `Button.h` / `Button.cpp`：按钮类（退出、重启）。
- `TextBox.h` / `TextBox.cpp`：状态文本框。
- `stdafx.h`：预编译头（建议把 EasyX 放在这里）。
- 资源与其它辅助文件同目录下。

## 依赖
- Visual Studio 2022（中文版） — 推荐使用默认 MSVC 工具集。
- EasyX 图形库（请安装对应平台的 EasyX SDK）。注意 EasyX 通常为 32 位库，若使用 32 位库请将 VS 平台设为 `Win32`（x86）。

## 配置与编译（建议）
1. 安装 EasyX SDK 并记下安装目录（例如 `C:\EasyX`），确保包含目录下有 `easyx.h`，lib 目录有 `.lib` 文件。  
2. 在 Visual Studio 中打开解决方案，右键项目名 -> 选择 __属性__（Project Properties）。  
3. 在 __Configuration__ 与 __Platform__ 中选择你要编译的配置（如 `Debug` / `Win32`）。  
4. 设置包含目录：进入 __Configuration Properties > C/C++ > General__，在 __Additional Include Directories__ 添加 EasyX 的 `include` 目录（如 `C:\EasyX\include`）。  
5. 设置库目录与依赖（若需要）：在 __Linker > General > Additional Library Directories__ 添加 `C:\EasyX\lib`，并在 __Linker > Input > Additional Dependencies__ 添加相应的 `.lib`（例如 `easyx.lib`，以你的 SDK 为准）。  
6. 预编译头：若项目启用了预编译头（默认模板通常启用），请确保每个 `.cpp` 文件首行包含 `#include "stdafx.h"`，并在 `stdafx.h` 中加入：
````````cpp
#include <easyx.h>
````````

建议把 EasyX 放到 `stdafx.h` 以保证所有编译单元可见。  
7. 清理并重建解决方案：使用 __Build > Clean Solution__，然后 __Build > Rebuild Solution__。

运行
- 在 Visual Studio 中按 __F5__（调试）或 __Ctrl+F5__（不调试）运行。
- 可在 `Debug\` 或 `Release\` 输出目录下直接运行生成的可执行文件。

游戏操作
- 鼠标左键：揭开方格。 
- 鼠标右键：插旗/取消旗（标记雷）。 
- 界面右侧的按钮：`重新开始`、`游戏结束`（退出）。

常见问题 & 解决（针对 `EM_MOUSE` 未声明）
- 问题原因：编译单元未包含 EasyX 头文件或预编译头配置不正确，导致 `EM_MOUSE` 等 EasyX 常量/类型不可见。 
- 解决方法要点：
1. 确认 `easyx.h` 的路径已加入 __Additional Include Directories__。 
2. 如果启用预编译头，确保每个 `.cpp` 文件第一行是 `#include "stdafx.h"`，并在 `stdafx.h` 中加入 `#include <easyx.h>`。 
3. 使用 __Build > Clean Solution__ → __Build > Rebuild Solution__。  
4. 可在 `GameFrame.cpp` 中紧跟 `#include "stdafx.h"` 后临时加入：
  ```cpp
  #ifndef EM_MOUSE
  #pragma message("WARNING: EM_MOUSE is NOT defined in this translation unit")
  #else
  #pragma message("INFO: EM_MOUSE is defined")
  #endif
  ```
  编译输出会告诉你 `EM_MOUSE` 是否可见，帮助定位包含链问题。 
5. 若 EasyX 只提供 32 位库，请将平台改为 `Win32`（在项目属性的 __Platform__ 中选择）。

开发建议
- 为便于移植，可将 EasyX 相关包含放在 `stdafx.h`，并把项目配置文档化。 
- 若计划在 x64 运行，请确认有兼容的 EasyX x64 版或改用其它跨平台图形库（如 SDL、SFML）。
