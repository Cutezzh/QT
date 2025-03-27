# QT

Learning Qt Records  at Ubuntu

## 2025.3.27

#### 1：新建一个项目

1. 作为初学者我们选择第一个Application(Qt)和 Qt Widgets Application 
2. 项目名称尽量选择英文，防止出错
3. 默认已经是选择 qmake 编译，主要用 qmake 生成 Makefile 用于项目的编译 
4. QMainWindow：主窗口类，主窗口具有主菜单栏、工具栏和状态栏。 类似于一般的应用程序的主窗口
   QWidget：是可视界面类的基类，也就是说 QMainWindow 类也是由 QWidget 继承封装而来。所以 QWidget 要比 QMainWindow 功能少一些  
   QDialog：对话框类，建立一个对话框界面。一般以 QMainWindow和 QWidget 作为基类的居多。==因为 QWidget 不带窗口标题栏等， 嵌入式里最好 QWidget==
   默认勾选“Generate form”，意思是生成 ui 窗体文件 mainwindow.ui  
5. Translation 这一项， Qt 提供了一个（ .ts） 的文件给您， .ts 是可读的翻译文件，使用简单的 XML 格式 
6. 勾选编译器，这个编译器是我们在安装组件时选择的，使用这个编译器可以编译出 Ubuntu版本上跑的可执行程序 ，不同平台有不同的编译器，生成可以当前平台可执行文件
7. 是否使用版本管理工具（git等）

注释：

| **工具**  | **定义**                                                     | **特点**                                                     | **适用场景**                     |
| --------- | ------------------------------------------------------------ | ------------------------------------------------------------ | -------------------------------- |
| **qmake** | Qt 自带的构建工具，通过 `.pro` 文件生成 Makefile 或 IDE 项目文件。 | - 简单易用，专为 Qt 优化- 自动处理 Qt 特性（MOC、UIC）- 功能有限，跨平台支持一般 | **小型 Qt 5 项目**，适合快速开发 |
| **CMake** | 跨平台构建系统生成器，通过 `CMakeLists.txt` 管理复杂项目。   | - 高度灵活，支持 Qt 和非 Qt 项目- 强大的跨平台能力- 学习曲线较陡 | **中大型项目**，Qt 6+ 官方推荐   |
| **Qbs**   | Qt 推出的现代化构建工具，直接编译而非生成中间文件。          | - 高效并行编译- 类 JavaScript 语法- 已被 Qt 官方弃用         | **实验性项目**，不推荐新项目使用 |

项目界面：

*  \*.pro 是项目管理文件，加入了文件或者删除了文件， Qt Creator 会自动修改这个\*.pro 文件。有时候需要打开这个\*.pro文件添加我们的设置项。

* Header 分组，存放项目内所有的头文件*.h

* Source 分组，存放项目内的所有 C++源码文件*.cpp

* Forms 分组，存放项目内所有界面文件*.ui。 *.ui 文件由 XML 语言描述组成，编译时会生成相应的cpp 文件，这样交叉编器就可以编译它了(只能通过图形界面修改其属性),里面主要分为 控件栏、显示窗口、对象栏、属性栏

#### 2：初识信号与槽

在ui界面添加一个按钮，点击后关闭这个窗口程序
简单来说：信号即是一个对象发出的信号，槽即是当这个对象发出这个信号时，对应连接的槽就发被执行或者触发  

方法一：首先拖动一个按钮对象到窗口，在窗口上方选择信号槽连接按钮，出现信号槽连接的界面，拖动那个按钮就会出现槽函数，显示从Qwidget继承的函数，按钮选择clicked()，MainWindow选择close()，点击ok

看不到信号与槽是如何连接的，函数在UI 文件编译后在生成的代码 ui_mainwindow.h 里  

方法二：选中按钮对象，右键，转到槽，可以发现放入的按钮对象都是继承其他槽函数的，点击ok后会跳转到槽函数里，在mainwindow.cpp里会生成一个on_pushButton_clicked  槽函数，this->close();调用 close()方法关闭整个程序 

#### 3：信号与槽

1. QT Designer方式开发程序简单，优点是可以比较直观的看到整体的布局，缺点是控件多了不好管理，统一用代码绘界面，可以==锻炼布局能力和代码逻辑能力==

2. 信号与槽关联是用 QObject::connect() 函数实现的，其基本格式是 

```c++
QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
```

sender 是发射信号的对象的名称，signal() 是信号名称。信号可以看做是特殊的函数， 需要带括号，有参数时还需要指明参数。 receiver 是接收信号的对象名称，slot() 是槽函数的名称，需要带括号，有参数时还需要指明参数  

一个信号可以连接多个槽，connect里的顺序不能乱

3. 断开连接QObject::disconnect  

```c++
bool QObject::disconnect(const QObject *sender, const char *signal, const QObject *receiver, const char *method)
```

* 断开一切与 myObject 连接的信号或槽

```c++
disconnect(myObject, 0, 0, 0);
//相当于myObject->disconnect();
```

* 断开所有连接到特定信号的东西  

```c++
disconnect(myObject, SIGNAL(mySignal()), 0, 0);
//myObject->disconnect(SIGNAL(mySignal()));
```

* 与指定的接收者断开连接

```c++
disconnect(myObject, 0, myReceiver, 0);
//myObject->disconnect(myReceiver);
```

4. 由于信号只需声明， 无需定义。 所以我们只需要在 mianwindow.h 里声明信号即可

5. 在 mianwindow.h 里直接声明槽，在 mianwindow.cpp 里实现槽的定义
   槽的特点：1）槽可以是任何成员函数、普通全局函数、静态函数；2）==槽函数和信号的参数和返回值要一致==

6. 声明 信号、槽、对象，这个测试是首先pushbutton这个对象setText，然后这个对象发送clicked信号1，它本身接收并执行pushbuttonclicked这个槽函数1，槽函数1实现一个pushbuttontextchanged信号2的发射，信号2连接到changedbuttontext这个槽函数2，槽函数2实现对pushbutton这个对象setText。

7. |                                  一般快捷键                           |									|
   | :--------------------------------: | :------------------------: |
   | 新建文件或项目(N)                  | Ctrl + N                   |
   | 关闭当前窗口/关闭当前文件          | Ctrl + W                   |
   | 关闭所有文件                       | Ctrl + Shfit + W           |
   | 关闭当前文件（windows）            | Ctrl + F4                  |
   | 运行                               | Ctrl + R                   |
   | 返回上一级（返回），常用于跳转代码 | Alt + ←（方向左键）        |
   | 进入下一级（前进），常用于跳转代码 | Alt + →（方向右键）        |
   | Qt 会自动排版对齐代码              | Ctrl + I                   |
   | 减小字体大小                       | Ctrl+- (Ctrl+鼠标滚轮向下) |
   | 增加字体大小                       | Ctrl++ (Ctrl+鼠标滚轮向上) |
   | 重置字体大小                       | Ctrl+0                     |
   | 折叠                               | Ctrl+<                     |

8. |      常用快捷键      |                            |
   | :------------------: | :------------------------: |
   |         展开         |           Ctrl+>           |
   |        复制行        |          Ctrl+Ins          |
   |      复制到行下      |       Ctrl+Alt+Down        |
   |      复制到行上      |        Ctrl+Alt+Up         |
   | 在当前行上方插入新行 |      Ctrl+Shift+Enter      |
   | 在当前行下方插入新行 |         Ctrl+Enter         |
   |    查看剪切板历史    |        Ctrl+Shift+V        |
   |        剪切行        |         Shift+Del          |
   |        追加行        |           Ctrl+J           |
   |    向下移动当前行    |      Ctrl+Shift+Down       |
   |    向上移动当前行    |       Ctrl+Shift+Up        |
   |  切换函数声明/定义   | Ctrl + 鼠标左键/Shift + F2 |
   |     编辑信号和槽     |             F4             |
   |  跳转至以}结尾的块   |           Ctrl+}           |
   |  跳转至以{开始的块   |           Ctrl+{           |
   |   打开类型层次窗口   |        Ctrl+Shift+T        |

9. 一般面向对象编程，都是一个类一个头文件和CPP文件，在A类下编程，this指向调用该函数的A类对象

#### 4：QT控件

##### 按钮

1. QPushButton:下压按钮
   \-QPushButton 继承 QAbstractButton 类，==被 QCommandLinkButton继承==。
   \-通常用于执行命令或触发事件。
2. QToolButton:工具按钮
   \-QToolButton 继承 QAbstractButton 类。
   \-是一种用于命令或者选项的可以快速访问的按钮，通常在 ToolBar 里面。
   \-通常==显示的是图标==，而不是文本标签。
   \-ToolButton==支持自动浮起==。在自动浮起模式中，按钮只有在鼠标指向它的时候才绘制三维的框架。
3. QRadioButton:选择按钮
   \-QRadioButton 继承 QAbstractButton 类。
   \- RadioButton单选按钮（单选框）通常成组出现，用于提供两个或多个互斥选项。
4. QCheckBox:检查框
   \-QCheckBox 继承 QAbstractButton类。
   \-复选按钮（复选框）与 RadioButton的区别是选择模式，单选按钮提供多选一，复选按钮提供多选多。
5. QCommandLinkButton:命令链接按钮
   \-QCommandLinkButton 继承 QPushButton。
   \-CommandLinkButton 除带有正常的按钮上的文字描述文本外，默认情况下，它也将携带一个箭头图标，表明按下按钮将打开另一个窗口或页面
6. QDialogButtonBox:对话框按钮
   \-QDialogButtonBox 继承 QWidget
   \-常用于对话框里自定义按钮，比如“确定”和“取消” 按钮

