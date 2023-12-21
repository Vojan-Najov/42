#!/bin/bash

func_link() {
rm -f ~/Library/Caches/Homebrew
mkdir -p /opt/goinfre/ccartman/Caches
mkdir -p /opt/goinfre/ccartman/Caches/Homebrew
ln -s /opt/goinfre/ccartman/Caches/Homebrew /Users/ccartman/Library/Caches/.
}

cd /opt/goinfre/ccartman
if [ -e homebrew ]
then
  echo "Homebrew installed"
else
  func_link
  git clone https://github.com/Homebrew/brew homebrew

  eval "$(/opt/goinfre/ccartman/homebrew/bin/brew shellenv)"
  brew update --force --quiet
  chmod -R go-w "$(brew --prefix)/share/zsh"
fi

func_link
eval "$(/opt/goinfre/ccartman/homebrew/bin/brew shellenv)"
brew update --force --quiet
chmod -R go-w "$(brew --prefix)/share/zsh"

which -s lcov
if [ "$?" -ne 0 ]
then
  brew install lcov
fi

brew install googletest

brew install htop

brew install gcovr

brew install wget

brew install lcov

brew install cpplint

brew install --HEAD LouisBrunner/valgrind/valgrind

brew install texlive
