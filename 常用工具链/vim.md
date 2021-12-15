
vim 的实用配置

1 Vim简介

神器无需解释

2 Vim Configuration

配置可以直接使用网友共享的优化配置：
https://github.com/amix/vimrc

安装命令：
```
git clone --depth=1 https://github.com/amix/vimrc.git ~/.vim_runtime
sh ~/.vim_runtime/install_awesome_vimrc.sh
```

3 Vim Plugins - NERDTree
Vim插件，装了这个插件，便可以显示树形目录结构。
```
https://github.com/scrooloose...
```

安装命令：
```
git clone https://github.com/scrooloose/nerdtree.git ~/.vim/bundle/nerdtree
```

重启Vim，在命令模式下输入NERDTree即可开启目录展示，默认是当前路径。
```
:NERDTree
```

+ 参考

来自网摘 https://segmentfault.com/a/1190000018761850