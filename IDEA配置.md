## IDEA配置

archetypeCatalog    internal


### 常用
一键格式化代碼: Ctrl+Alt+L

Shift+Shift All 无论您想要搜啥都能找到

Ctrl+N Classes 按照类名搜索类

Ctrl+Shift+N Files 按照文件名搜索文件

Symbols

Ctrl+Shift+A Actions

### 【常规】
1. Ctrl+Shift + Enter,语句完成
2. "!”,否定完成,输入表达式时按 "!”键
3. Ctrl+E,最近的文件
4. Ctrl+Shift+E,最近更改的文件
5. Shift+Click,可以关闭文件
6. Ctrl+[ OR ],可以跑到大括号的开头与结尾
7. Ctrl+F12,可以显示当前文件的结构
8. Ctrl+F7,可以查询当前元素在当前文件中的引用,然后按 F3 可以选择
9. Ctrl+N,可以快速打开类
10. Ctrl+Shift+N,可以快速打开文件
11. Alt+Q,可以看到当前方法的声明 当方法体很长时,滚动到看不到方法签名,这个快捷键可以快速看到方法签名
12. Ctrl+P,可以显示参数信息
13. Ctrl+Shift+Insert,可以选择剪贴板内容并插入 有一个剪切板历史 可以选择
14. Alt+Insert,可以生成构造器/Getter/Setter等
15. Ctrl+Alt+V,可以引入变量.例如:new String();  自动导入变量定义
16. Ctrl+Alt+T,可以把代码包在一个块内,例如:try/catch 与打开终端的快捷键冲突 改成Alt+T 虽然会和工具条Tools菜单冲突,但这个缺点能接受
17. Ctrl+Enter,导入包,自动修正 当错误是没有导入包的时候
18. Ctrl+Alt+L,格式化代码
19. Ctrl+Alt+I,将选中的代码进行自动缩进编排,这个功能在编辑 JSP 文件时也可以工作
20. Ctrl+Alt+O,优化导入的类和包
21. Ctrl+R,替换文本
22. Ctrl+F,查找文本
23. Ctrl+Shift+Space,自动补全代码
24. Ctrl+空格,代码提示(与系统输入法快捷键冲突)已改成Alt+/
25. Ctrl+Shift+Alt+N,查找类中的方法或变量
26. Alt+Shift+C,最近的更改
27. Alt+Shift+Up/Down,上/下移一行
28. Shift+F6,重构 - 重命名
29. Ctrl+X,删除行
30. Ctrl+D,复制行
31. Ctrl+/或Ctrl+Shift+/,注释(//或者/**/)
32. Ctrl+J,自动代码(例如:serr)
33. Ctrl+Alt+J,用动态模板环绕
34. Ctrl+H,显示类结构图(类的继承层次)
35. Ctrl+Q,显示注释文档
36. Alt+F1,查找代码所在位置
37. Alt+1,快速打开或隐藏工程面板
38. Ctrl+Alt+left/right,返回至上次浏览的位置
39. Alt+left/right,切换代码视图
40. Alt+Up/Down,在方法间快速移动定位
41. Ctrl+Shift+Up/Down,向上/下移动语句 无效
42. F2 或 Shift+F2,高亮错误或警告快速定位
43. Tab,代码标签输入完成后,按 Tab,生成代码
44. Ctrl+Shift+F7,高亮显示所有该文本,按 Esc 高亮消失
45. Alt+F3,逐个往下查找相同文本,并高亮显示
46. Ctrl+Up/Down,光标中转到第一行或最后一行下
47. Ctrl+B/Ctrl+Click,快速打开光标处的类或方法(跳转到定义处)
48. Ctrl+Alt+B,跳转到方法实现处
49. Ctrl+Shift+Backspace,跳转到上次编辑的地方
50. Ctrl+O,重写方法
51. Ctrl+Alt+Space,类名自动完成
52. Ctrl+Alt+Up/Down,快速跳转搜索结果
53. Ctrl+Shift+J,整合两行
54. Alt+F8,计算变量值
55. Ctrl+Shift+V,可以将最近使用的剪贴板内容选择插入到文本
56. Ctrl+Alt+Shift+V,简单粘贴
57. Shift+Esc,不仅可以把焦点移到编辑器上,而且还可以隐藏当前(或最后活动的)工具窗口
58. F12,把焦点从编辑器移到最近使用的工具窗口
59. Shift+F1,要打开编辑器光标字符处使用的类或者方法 Java 文档的浏览器
60. Ctrl+W,可以选择单词继而语句继而行继而函数  不断扩大选择
61. Ctrl+Shift+W,取消选择光标所在词 不断缩小选择
62. Alt+F7,查找整个工程中使用地某一个类,方法或者变量的位置
63. Ctrl+I,实现方法
64. Ctrl+Shift+U,大小写转化
65. Ctrl+Y,删除当前行
66. Shift+Enter,向下插入新行 Ctrl+Enter,上插一行
67. psvm/sout,main/System.out.println(); Ctrl+J,查看更多 Ctrl+J没有Alt+/好用
68. Ctrl+Shift+F,全局查找 与搜狗输入法繁简体转换冲突
69. Ctrl+F,查找/Shift+F3,向上查找/F3,向下查找
70. Ctrl+Shift+S,高级搜索 无效
71. Ctrl+U,转到父类
72. Ctrl+Alt+S,打开设置对话框
73. Alt+Shift+Inert,开启/关闭列选择模式
74. Ctrl+Alt+Shift+S,打开当前项目/模块属性
75. Ctrl+G,定位行
76. Alt+Home,跳转到导航栏
77. Ctrl+Enter,上插一行 Shift+Enter 下插一行
78. Ctrl+Backspace,按单词删除
79. Ctrl+"+/-",当前方法展开,折叠
80. Ctrl+Shift+"+/-",全部展开,折叠


### 【调试部分,编译】
1. Ctrl+F2,停止
2. Alt+Shift+F9,选择 Debug
3. Alt+Shift+F10,选择 Run
4. Ctrl+Shift+F9,编译
5. Ctrl+Shift+F10,运行
6. Ctrl+Shift+F8,查看断点
7. F8,步过
8. F7,步入
9. Shift+F7,智能步入
10. Shift+F8,步出
11. Alt+Shift+F8,强制步过
12. Alt+Shift+F7,强制步入
13. Alt+F9,运行至光标处
14. Ctrl+Alt+F9,强制运行至光标处
15. F9,恢复程序
16. Alt+F10,定位到断点
17. Ctrl+F8,切换行断点
18. Ctrl+F9,生成项目
19. Alt+1,项目
20. Alt+2,收藏
21. Alt+6,TODO
22. Alt+7,结构
23. Ctrl+Shift+C,复制路径
24. Ctrl+Alt+Shift+C,复制引用,必须选择类名
25. Ctrl+Alt+Y,同步
26. Ctrl+~,快速切换方案(界面外观,代码风格,快捷键映射等菜单)
27. Shift+F12,还原默认布局
28. Ctrl+Shift+F12,隐藏/恢复所有窗口
29. Ctrl+F4,关闭
30. Ctrl+Shift+F4,关闭活动选项卡
31. Ctrl+Tab,转到下一个拆分器
32. Ctrl+Shift+Tab,转到上一个拆分器


### 【重构】
1. Ctrl+Alt+Shift+T,弹出重构菜单
2. Shift+F6,重命名
3. F6,移动
4. F5,复制
5. Alt+Delete,安全删除
6. Ctrl+Alt+N,内联


### 【查找】
1. Ctrl+F,查找
2. Ctrl+R,替换
3. F3,查找下一个
4. Shift+F3,查找上一个
5. Ctrl+Shift+F,在路径中查找
6. Ctrl+Shift+R,在路径中替换
7. Ctrl+Shift+S,搜索结构
8. Ctrl+Shift+M,替换结构
9. Alt+F7,查找用法
10. Ctrl+Alt+F7,显示用法
11. Ctrl+F7,在文件中查找用法
12. Ctrl+Shift+F7,在文件中高亮显示用法


### 【VCS】
1. Alt+~,VCS 操作菜单
2. Ctrl+K,提交更改
3. Ctrl+T,更新项目
4. Ctrl+Alt+Shift+D,显示变化


以上皆由网络整理,不作商业用途,与本人无关
