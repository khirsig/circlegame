# circlegame
W.I.P.

## Quickstart
	just run the install script

## Install dependencies manually

You need to have brew installed to install raylib

### Install brew
for 42HN-Local-Mac
```
    rm -fr /goinfre/$USER/.brew $HOME/.brew &&
    git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew &&
    echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc &&
    export PATH=$HOME/goinfre/.brew/bin:$PATH &&
    brew update
```
for other devices
```
    $HOME/.brew &&
    git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew &&
    echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc &&
    export PATH=$HOME/.brew/bin:$PATH &&
    brew update
```


### Install raylib
```
    brew install raylib
```

### Compiling and launch Circlegame
clone the repo, then run make inside the folder
```
    make run
```

