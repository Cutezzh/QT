# QT

> Learning Qt Records  at Ubuntu
>
> 2025.3.27

## 1：新建一个项目

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

## 2：初识信号与槽

在ui界面添加一个按钮，点击后关闭这个窗口程序
简单来说：信号即是一个对象发出的信号，槽即是当这个对象发出这个信号时，对应连接的槽就发被执行或者触发  

方法一：首先拖动一个按钮对象到窗口，在窗口上方选择信号槽连接按钮，出现信号槽连接的界面，拖动那个按钮就会出现槽函数，显示从Qwidget继承的函数，按钮选择clicked()，MainWindow选择close()，点击ok

看不到信号与槽是如何连接的，函数在UI 文件编译后在生成的代码 ui_mainwindow.h 里  

方法二：选中按钮对象，右键，转到槽，可以发现放入的按钮对象都是继承其他槽函数的，点击ok后会跳转到槽函数里，在mainwindow.cpp里会生成一个on_pushButton_clicked  槽函数，this->close();调用 close()方法关闭整个程序 

## 3：信号与槽

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

QT对象树机制，目的就是为了方便管理内存

为什么要设置父对象？因为窗口互相联系，比如A需要显示在B上，A需要指定B为父对象
在父对象销毁的时候，子对象也会被销毁

```C++
/* 1.构造函数传参 */
pushButton = new QPushButton(this);
/* 2.通过setParent（）方法 */
pushButton = new QPushButton();
pushButton->setParent(this);
```

## 4：QT控件

QT样式表是一种强大的QT机制，它允许自定义小部件的外观

### 按钮

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

```c++
MainWindow::MainWindow(QWidget *parent){
        pushButton = new QPushButton(this);//创建父子关系
        pushButton->setText("Text");//设置按钮的文本属性
        pushButton->setGeometry(50, 50, 100, 50);//设置按钮的大小
        this->resize(800, 480);//设置主窗口的大小
}
```

* ==QPushButton：==
  \-声明一个 QPushButton 对象 
  \-声明对象 pushButton1 的槽函数 
  \-实例化按钮对象 
  \-信号槽连接 
  \-槽函数的实现 

* QToolButton：
  \-声明 QToolButton 对象和 QtoolBar 对象 
  \-初始化 toolBar（工具条/工具栏）对象
  \-初始化 toolButton（工具按钮）对象
  \-设置工具按钮的样式
  \-将 toolButton（工具按钮）添加到 toolBar（工具条/工具栏）上  
* ==QRadioButton==
  \-声明两个 QRadioButton 对象
  \-实例化对象
  \-设置两个 QRadioButton 的位置和显示大小
  \-设置两个 QRadioButton 的显示文本
  \-设置初始状态， radioButton1 的 Checked 为 false,另一个为 true
  \-在 main.cpp 里加载 qss 文件

* ==QCheckBox==
  \-声明一个 QCheckBox 对象
  \-声明 QCheckBox 的槽函数，并带参数传递，用这个参数接收信号的参数
  \-实例化对象  初始化三态复选框的状态为 Checked  
  \-开启三态模式，必须开启，否则只有两种状态，即 Checked 和 Unchecked  
  \-连接 checkBox 的信号 stateChanged(int)，与我们定义的槽checkBoxStateChanged(int)连接  
  \-槽函数的实现  判断 checkBox 的 state 状态，设置 checkBox 的文本  
  \-style.qss  设置全局样式

* QCommandLinkButton
  \-声明一个 QCommandLinkButton 对象
  \-声明槽函数，用于点击 commandLinkButton 后触发 
  \-引入桌面服务，用来打开系统文件夹对话框  引入 QUrl  
  \-实例化对象  信号槽连接  
  \-调用系统服务打开/home 目录  

* QDialogButtonBox  

  常用按钮
  button_Box = new QDialogButtonBox(QDialogButtonBox::Ok 
  | QDialogButtonBox::Cancel 
  | QDialogButtonBox::Open 
  | QDialogButtonBox::Save 
  | QDialogButtonBox::Close 
  | QDialogButtonBox::Discard 
  | QDialogButtonBox::Apply 
  | QDialogButtonBox::Reset 
  | QDialogButtonBox::RestoreDefaults 
  | QDialogButtonBox::Help 
  | QDialogButtonBox::SaveAll);  
  \-声明一个 QDialogButtonBox 对象  
  \-声明信号槽，带 QAbstractButton *参数，用于判断点击了哪个按钮  
  \-pushButton = new QPushButton(tr("自定义"));  tr() 是 Qt 的**多语言翻译函数**，标记需要国际化的字符串
  \-自定义的按钮需要加入到QDialogButtonBox中

### 输入窗口部件

1. Comb Box:组合框
   \-QComboBox 继承 QWidget 类  
   \-通常用于用户显示选项列表的方法，这种方法占用最少的屏幕空间  
2. Font Comb Box:字体组合框
   \-QFontComboBox 继承 QComboBox  
   \-常用于工具栏，与 ComboBox 一起用于控制字体大小，并与两个 ToolButtons 一起用于粗体和斜体  
3. Line Edit:单行编辑框
   \-QLineEdit 继承 QWidget  
   \-允许用户使用一组有用的编辑函数输入和编辑一行纯文本，包括撤消和重做、剪切和粘贴以及拖放  
4. Text Edit:文本编辑框
   \-QTextEdit 继承 QAbstractScrollArea  
   \-QTextEdit 用于段落和字符  QTextEdit 可以显示图像，列表和表格  
5. Plain Text Edit:纯文本编辑框
   \-QPlainTextEdit 是一个支持纯文本的高级查看器/编辑器    
6. Spin Box:数字旋转框
   \-QSpinBox 继承 QAbstractSpinBox  
   \-用于处理整数和离散值  
7. Double Spin Box:双精度数字旋转框
   \-QDoubleSpinBox 继承 QAbstractSpinBox  
   \-QDoubleSpinBox 则用于处理浮点值  
8. Time Edit:时间编辑框
   \-QTimeEdit 继承 QDateTimeEdit  
   \-用于编辑时间  
9. Date Edit:日期编辑框
   \-QDateEdit 继承 QDateTimeEdit  
   \-用于编辑日期  
10. Date/Time Edit:日期时间编辑框
    \-QDateTimeEdit 类提供了一个用于编辑日期和时间的小部件  
11. Dial:数字拨盘框
    \-QDial 类提供了一个圆形范围控制(如速度计或电位器)  
12. Horizontal Scroll Bar:水平滚动条 Vertical Scroll Bar:垂直滚动条
    \-QScrollBar 继承 QAbstractSlider  
    \-提供垂直或水平滚动条，允许用户访问比用于显示文档的小部件大的文档部分  
13. Horizontal Slider:水平滑动条 Vertical Slider:垂直滑动条
    \-QSlider 继承 QAbstractSlider
    \-QSlider 类提供垂直或水平滑动条小部件， 滑动条是用于控制有界值的典型小部件    
14. Key sequence Edit:按键序列编辑框
    \-QKeySequenceEdit 继承 QWidget  
    \-通常用作快捷方式  

### 显示窗口部件

1. Label:标签
   \-用于文本或图像显示的小部件  

2. Text Browser:文本浏览器
   \-QTextBrowser 继承 QTextEdit  
   \-提供了一个具有超文本导航的文本浏览器  

3. Graphics View:图形视图
   \-QGraphicsView 继承 QAbstractScrollArea  
   \-提供了基于图元的模型/视图编程  

4. Calendar Widget:日历

   \-QCalendarWidget 继承 QWidget  

5. LCD Number:液晶数字
   \-QLCDNumber 继承 QFrame  
   \-使用 display()插槽很容易连接到数据源  

6. Progress Bar:进度条
   \-QProgressBar 继承 QWidget  
   \-提供了一个水平或垂直的进度条。进度条用于向用户显示操作的进度，并向他们确认应用程序仍在运行  

7. Horizontal Line:水平线

8. Vertial Line:垂直线

9. OpenGL Widget:开放式图形库工具

10. QQuick Widget:嵌入式 QML 工具

### 布局管理



### 空间间隔



### 容器



### 项目视图组



### 项目控件组



## 5：笔记

1. margin：容器外边距

2. padding：容器内边距

3. QHBoxLayout：水平布局
   * spacing ：间隔距离
   * stretch：拉伸因子 （this->setLayout(ui->horizontalLayout) 这样容器会随界面同步变化（填满整个水平布局）
   * sizePolicy：大小策略

4. QVBoxLayout：垂直布局

5. QGridLayout：网格布局

6. QSplitter
   * orientation：设置方向，可设置水平或垂直方向
   * opaqieResize：为false时，拖动时会显示一条灰色的线，释放鼠标后再显示分割线条；默认为true，实时更新控件大小
   * childrenCollapsible：为true时，可以将子部件的大小调整为0

7. QSpacerltem：隔离弹簧

   * orientation：方向属性，可设置水平或垂直方向
   * sizeType：大小类型
   * sizeHint：默认大小

8. QLineEdit：单行文本编辑

9. QDialog：弹出对话框

   * setWindowFlag(Qt::FramelessWindowHInt);设置无边框
   * setAttribute(Qt::WA_TranslucentBackground);设置背景透明

10. QScroollArea：面板滚动效果

   ```c++
   /*样式表*/
   QScrollBar:vertical{width:20px;background: white }//设置背景色和宽度
   QScrollBar::handle:vertical {background: rgba(200, 200, 200, 50%);border-radius:10px }//颜色、透明度和倒角
   QScrollBar::handle:vertical:hover {background: rgba(200, 200, 200, 90%) }//放上去后透明度变化
   QScrollBar::add-line:vertical {width: 0px; height: 0px }
   QScrollBar::sub-line:vertical {width: 0px; height: 0px }
   ```

   ==设置倒角时，注意不要超过宽度的一半==

11. QTabWidget：面板切换效果

    ```C++
    ui->tabWidget->setCurrentIndex(currentRow);//设置列表槽函数到tab切换
    this->setLayout(ui->horizontalLayout);//设置布局随窗口大小变化
    /*样式表*/
    QTabBar::tab{ width: 0px; height: 0px}//设置切换块的大小，隐藏后类似于stacked Widget
    ```

12. QLIstWidget：列表面板

    ```C++
    /* 添加项 */    
    ui->listWidget->addItem("zzh1");
    ui->listWidget->addItem("zzh2");
    ui->listWidget->addItem("zzh3");
    /* 移除项 */
    ui->listWidget->takeItem(0);//和数组一样通过访问下标
    /* 插入项，是在下标的前面插入 */
    ui->listWidget->insertItem(0, "cutezzh");
    
    /* 常用的信号函数 */
    currentRowChanged(int);//切换内容之后做出的操作
    
    /* 单独设置列表内的内容 */
    #include <QListWidgetItem>
    #include "qqitem.h"//自定义的类，用来创建列表的内容
    QQItem *qqItem0 = new QQItem(":/icons/icon2.jpg", true, "super man");//初始化新建的内容
    QListWidgetItem *item0 = new QListWidgetItem();// 创建空列表项
    
    ui->listWidget->addItem(item0);//列表项加入到列表面板中
    ui->listWidget->setItemWidget(item0, qqItem0);//设置每个列表的内容
    ```

    * 设置自定义内容的时候，listwidget上显示的是自定义的widget窗口大小，所以在自定义的时候自定义的widget里的布局要显示在设定好geometry的范围内显示，不然你的listwidget显示列表区域的大小会限定死，我目前还没有好的解决方法，继续学习可能会吧

13. QFile：文本读写

    ```c++
    /* 找到文件 */
    QString filename = QFileDialog::getOpenFileName//返回的是一个字符串，包括了路径+文件名字
    /* 打开文件 */
    file.setFileName(filename);//设置 QFile 对象要操作的文件名或路径
        
    if(!file.open(QIODevice::ReadOnly)){
            qDebug() << "open the file fail" << endl;
            return;
        }//需要判断文件是否被打开
    /* 读写文件 */
    readAll(), readLine(), write()
     
    ui->textEdit->setPlainText(file.readAll());//QString 的构造函数自动把QByteArray 直接转换为 QString
    
    /* 关闭文件 */
    file.write(ui->textEdit->toPlainText().toUtf8());//将编辑面板的文件写成字符
    close()//一般点击面板上的关闭之前保存文件
    ui->textEdit->clear();//最后清空面板
    ```

14. QPainter：绘制图形

    ```C++
    void Widget::paintEvent(QPaintEvent *event)//需要重写
    {
        Q_UNUSED(event);
        QPainter painter(this);//this是指定绘图对象
        
        QPen pen;//设置画笔
        pen.setWidth(3);
        pen.setColor(QColor(200, 190, 87));
        QBrush brush("#888888");//填充
    
        painter.setPen(pen);
        painter.setBrush(brush);
    
        painter.drawRect(50, 100, 100, 200);//画矩形
    
        QPolygon polygon;//画多边形
        polygon.setPoints(3, 350, 200, 250, 300, 450, 300);
        painter.drawPolygon(polygon);
    
        painter.drawLine(500, 300, 500, 100);//画直线
        painter.drawEllipse(100, 400, 200, 100);//画椭圆
    
        QRectF qrectf(50, 100, 100, 200);//画文字
        painter.drawText(qrectf,Qt::AlignCenter, "cuteZZH");
    
        QPainterPath path;//画路径
        path.moveTo(20, 80);
        path.lineTo(20, 30);
        path.cubicTo(80, 0, 50, 50, 80, 80);
        painter.drawPath(path);
    }
    
    /******************轮播文字*************************/
    QFont font;//创建字体对象
    int offset;//偏移量
    QTimer *timer;//定时器对像
    QString textContent;//要显示的字符串
    int textContentWidth;//字符串的长度
    
    QFontMetrics fontMertics(font);//根据font的参数计算尺寸
    textContentWidth = fontMertics.width(textContent);//计算字符串的参数
    
    timer = new QTimer(this);
    timer->start(50);//50ms
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));//溢出信号连接到槽函数
    
    QRect rectf = this->rect();//文字显示的区域
    rectf.setLeft(this->width() - offset);//将文字从最左边起
    painter.drawText(rectf, Qt::AlignVCenter, textContent);//让文字居中显示
    
    void Widget::onTimerTimeout()//定时器槽函数，每隔xms，offset自增，直到超过显示区域加文字长度，这样文字必须全部放完才能出现
    {
        if(offset < this->width() + textContentWidth){
            offset += 5;
        }else offset = 0;
    
        this->update();//必须更新窗口
    
    }
    ```

15. QChart：图表

    ==QT += charts==

    ```C++
    #include <QChart>//图表类
    #include <QChartView>//图表视图类
    /* 创建一个图表视图 */
    QChartView *charView = new QChartView();
    /* 创建一个图表 */
    QChart *chart = new QChart();
    /* 创建坐标轴 */
    QValueAxis *valueAxisX = new QValueAxis();
    QValueAxis *valueAxisY = new QValueAxis();
    /* 设置坐标轴的范围 */
    valueAxisX->setRange(0, 5000);
    valueAxisY->setRange(0, 100);
    /* 设置坐标轴的标题和显示的格式 */ 
    valueAxisX->setTitleText("Time/ms");
    valueAxisY->setTitleText("Temperature/oC");
    valueAxisX->setLabelFormat("%d");
    valueAxisY->setLabelFormat("%d");
    /* 图标添加坐标轴 */
    chart->createDefaultAxes();
    chart->addAxis(valueAxisX, Qt::AlignBottom);
    chart->addAxis(valueAxisY, Qt::AlignLeft);
    /* 设置图表的标题以及图例显示是否需要 */
    chart->setTitle("temperature versus time curve");
    chart->legend()->setVisible(false);
    /* 创建曲线对象添加它的点，设置曲线的颜色 */
    QSplineSeries *splineSeries = new QSplineSeries();
    splineSeries->append(0, 20);
    splineSeries->append(1000, 40);
    splineSeries->append(2000, 50);
    splineSeries->append(3000, 20);
    splineSeries->append(4000, 60);
    splineSeries->append(5000, 30);
    QPen pen(QColor(0x888888));
    splineSeries->setPen(pen);
    /* 图表添加曲线 */
    chart->addSeries(splineSeries);
    /* 将曲线的数据与坐标轴联系起来，注意，这个要在图表添加曲线之后 */
    //附属到坐标轴上去
    splineSeries->attachAxis(valueAxisX);
    splineSeries->attachAxis(valueAxisY);
    /* 将图表放置于图表视图中 */
    ui->qchartview->setChart(chart);
    ```

16. QPropertyAnimation：属性动画效果

    ```C++
    /***************************几何动画******************************/
    /* 几何属性动画初始化 */
    propertyAnimation0 = new QPropertyAnimation(ui->geometrywidget, "geometry");
    /* 设置动画起始值 */
    propertyAnimation0->setStartValue(QRect(0, 0, 100, 100));
    /* 设置某个时间段值 *///中间值是你设置总时间的比例
    propertyAnimation0->setKeyValueAt(0.5, QRect(400, 0, 100, 100));
    /* 设置结束值 */
    propertyAnimation0->setEndValue(QRect(400, 200, 200, 200));
    /* 设置动画时长 */
    propertyAnimation0->setDuration(2000);
    /* 设置动画循环周期 */
    propertyAnimation0->setLoopCount(1);
    /* 设置动画的缓和曲线 *///动画变化的速度按照什么曲线
    propertyAnimation0->setEasingCurve(QEasingCurve::OutCubic);
    /***************************颜色动画******************************/
    //颜色属性效果类，这个动画不是直接作用于widget，需要一个中间状态作用
    #include <QGraphicsColorizeEffect>
    QGraphicsColorizeEffect *graphicsColorizeEffect = new QGraphicsColorizeEffect(this);
    ui->colorwidget->setGraphicsEffect(graphicsColorizeEffect);
    propertyAnimation1 = new QPropertyAnimation(graphicsColorizeEffect, "color");
    propertyAnimation1->setStartValue(QColor(Qt::yellow));
    propertyAnimation1->setEndValue(QColor(Qt::darkRed));
    propertyAnimation1->setDuration(3000);
    /***************************不透明动画******************************/
    //不透明属性效果类，这个动画不是直接作用于widget，需要一个中间状态作用
    #include <QGraphicsOpacityEffect>
    QGraphicsOpacityEffect *graphicsOpacityEffect = new QGraphicsOpacityEffect(this);
    ui->opacitywidget->setGraphicsEffect(graphicsOpacityEffect);
    propertyAnimation2 = new QPropertyAnimation(graphicsOpacityEffect, "opacity");
    propertyAnimation2->setStartValue(0.0);//范围是0.0 ~ 1.0 全透明~不透明
    propertyAnimation2->setEndValue(1.0);
    propertyAnimation2->setDuration(3000);
    ```

17. Q_PROPERTY：属性宏

    ```C++
    Q_PROPERTY(qreal money READ money WRITE setMoney)
    qreal money() const;
    void setMoney(qreal money);
    //qreal money：声明属性类型为qreal（通常等同于double），属性名为money。
    //READ money：指定读取属性值的函数为money()，该函数需返回qreal类型的当前值。
    //WRITE setMoney：指定写入属性值的函数为setMoney(qreal)，该函数接受一个qreal参数用于更新属性值
    rich->setProperty("money", 100);
    //通过setProperty方法可以去调用setMoney函数，字符串里是自定义类型的名字（qreal 后面的money）
    
    //在动画里就可以播放自定义的属性
    ```

18. QThread：多线程

    ```C++
    //一个应用程序至少要一个进程 QProcess
    //一个进程至少会有一个线程 QThread
    #include <QThread>
    class MyThread : public QThread
    {
        Q_OBJECT
    
    public:
        MyThread(QWidget *parent = nullptr){
            Q_UNUSED(parent)
        }
        ~MyThread(){
            
        }
        void run() override{//只有这个run()方法在新的线程里面
            deleteLater();//进程结束后，要记得销毁对象，不然容易造成内存泄漏
        } 
    };
    myThread->start();//启动线程
    if(!myThread->isFinished())
    myThread->terminate();//终止线程
    ```

19. TCP服务端/ TCP客户端

    ==QT += network==

    通过QIODevice这个类读写接收

    ```C++
    #include <QTcpServer>
    #include <QTcpSocket>
    //发送一个连接信号
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(m_NewConnection()));
    QTcpSocket *tmpTcpSocket = tcpServer->nextPendingConnection();//与客户端连接
    ```

20. QUdpSocket

    ```c++
    //绑定端口
    udpSocket->bind(7755);
    //接收消息
    void Widget::readPendingDatagrams()
    {
        QByteArray tmpByteArray;
        tmpByteArray.resize(udpSocket->pendingDatagramSize());//重新定义数组的大小
        QHostAddress ipaddr;
        quint16 port;
        while (udpSocket->hasPendingDatagrams()) {
            udpSocket->readDatagram(tmpByteArray.data(), tmpByteArray.size(), &ipaddr, &port);
            ui->textBrowser->append("receive from:" + ipaddr.toString() + ":" + QString::number(port) + tmpByteArray);//打印发送者的ip地址和端口信息
        }
    }
    //单播消息
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress("127.0.0.1"), 7755);
    //广播消息
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::Broadcast, 7755);
    ```

21. 交叉编译

    `make distclean` 删除所有makefile编译的文件

22. Qt串口编程

    `QT += serialport`

    ```C++
    #include <QSerialPort>//串口类
    #include <QSerialPortInfo>//串口信息类
    // 扫描本机的串口，并且添加到下拉框里
    foreach (const QSerialPortInfo &info,
             QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(info.portName());
    }
    // 读取数据
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
    
    
    void Widget::on_pushButton_clicked(bool checked)
    {
        if (checked) {
            // 设置要打开的串口的名字
            serialPort->setPortName(ui->comboBox->currentText());
            // 设置波特率
            serialPort->setBaudRate(ui->comboBox_2->currentText().toInt());
            // 设置停止位
            serialPort->setStopBits(QSerialPort::StopBits(ui->comboBox_3->currentText().toInt()));
            // 设置数据位
            serialPort->setDataBits(QSerialPort::DataBits(ui->comboBox_4->currentText().toInt()));
            // 设置校验位
            switch (ui->comboBox_5->currentIndex()) {
            case 0:
                serialPort->setParity(QSerialPort::NoParity);
                break;
            case 1:
                serialPort->setParity(QSerialPort::EvenParity);
                break;
            case 2:
                serialPort->setParity(QSerialPort::OddParity);
                break;
            case 3:
                serialPort->setParity(QSerialPort::SpaceParity);
                break;
            case 4:
                serialPort->setParity(QSerialPort::MarkParity);
                break;
            default:
                break;
            }
            // 设置流控为无
            serialPort->setFlowControl(QSerialPort::NoFlowControl);
    
            if (!serialPort->open(QIODevice::ReadWrite)) {
                QMessageBox::about(this, "错误", "串口打开失败可能被占用了");
                return;
            }
    
            ui->comboBox->setEnabled(false);
            ui->comboBox_2->setEnabled(false);
            ui->comboBox_3->setEnabled(false);
            ui->comboBox_4->setEnabled(false);
            ui->comboBox_5->setEnabled(false);
    
            ui->pushButton->setText("关闭串口");
        } else {
            // 关闭串口
            serialPort->close();
            ui->comboBox->setEnabled(true);
            ui->comboBox_2->setEnabled(true);
            ui->comboBox_3->setEnabled(true);
            ui->comboBox_4->setEnabled(true);
            ui->comboBox_5->setEnabled(true);
            ui->pushButton->setText("打开串口");
        }
    }
    
    void Widget::readData()
    {
        // 接收数据
        ui->textBrowser->insertPlainText(serialPort->readAll());
    }
    
    void Widget::on_pushButton_2_clicked()
    {
        // 发送数据
        serialPort->write(ui->textEdit->toPlainText().toUtf8());
    }
    
    void Widget::on_pushButton_3_clicked()
    {
        // 清空发送的数据
        ui->textEdit->clear();
    }
    ```

    
