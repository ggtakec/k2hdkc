---
layout: contents
language: en-us
title: Build
short_desc: K2Hash based Distributed Kvs Cluster
lang_opp_file: buildja.html
lang_opp_word: To Japanese
prev_url: usage.html
prev_string: Usage
top_url: index.html
top_string: TOP
next_url: developer.html
next_string: Developer
---
# Build

This chapter consists of three parts:

* how to set up **K2HDKC** for local development
* how to build **K2HDKC** from the source code
* how to install **K2HDKC**

## 1. Install prerequisites

**K2HDKC** primarily depends on [FULLOCK](https://fullock.antpick.ax/index.html), [K2HASH](https://k2hash.antpick.ax/index.html) and [CHMPX](https://chmpx.antpick.ax/index.html). Each dependent library and the header files are required to build **K2HDKC**. We provide two ways to install them. You can select your favorite one.

* Use [GitHub](https://github.com/yahoojapan)  
  Install the source code of dependent libraries and the header files. You will **build** them and install them.
* Use [packagecloud.io](https://packagecloud.io/antpickax/stable)  
  Install packages of dependent libraries and the header files. You just install them. Libraries are already built.

### 1.1. Install each dependent library and the header files from GitHub

Read the following documents for details:  
* [FULLOCK](https://fullock.antpick.ax/build.html)
* [K2HASH](https://k2hash.antpick.ax/build.html)  
* [CHMPX](https://chmpx.antpick.ax/build.html)  

### 1.2. Install each dependent library and the header files from packagecloud.io

This section instructs how to install each dependent library and the header files from [packagecloud.io](https://packagecloud.io/antpickax/stable). 

**Note**: Skip reading this section if you have installed each dependent library and the header files from [GitHub](https://github.com/yahoojapan) in the previous section.

For DebianStretch or Ubuntu(Bionic Beaver) users, follow the steps below:
```bash
$ sudo apt-get update -y
$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh \
    | sudo bash
$ sudo apt-get install autoconf autotools-dev gcc g++ make gdb libtool pkg-config \
    libyaml-dev libfullock-dev k2hash-dev chmpx-dev -y
$ sudo apt-get install git -y
```

For Fedora28 or CentOS7.x(6.x) users, follow the steps below:
```bash
$ sudo yum makecache
$ sudo yum install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh \
    | sudo bash
$ sudo yum install autoconf automake gcc gcc-c++ gdb make libtool pkgconfig \
    libyaml-devel libfullock-devel k2hash-devel chmpx-devel -y
$ sudo yum install git -y
```

## 2. Clone the source code from GitHub

Download the **K2HDKC**'s source code from [GitHub](https://github.com/yahoojapan).
```bash
$ git clone https://github.com/yahoojapan/k2hdkc.git
```

## 3. Build and install

Just follow the steps below to build **K2HDKC** and install it. We use [GNU Automake](https://www.gnu.org/software/automake/) to build **K2HDKC**.

```bash
$ cd k2hdkc
$ sh autogen.sh
$ ./configure --prefix=/usr
$ make
$ sudo make install
```

After successfully installing **K2HDKC**, you will see the k2hdkc help text:
```bash
$ k2hdkc -h
[Usage]
k2hdkc [-conf <file path> | -json <json string>] [-ctlport <port>] [-comlog] [-no_giveup_rejoin] [-d [silent|err|wan|msg|dump]] [-dfile <file path>]
k2hdkc [ -h | -v ]
[option]
  -conf <path>         specify the configuration file(.ini .yaml .json) path
  -json <string>       specify the configuration json string
  -ctlport <port>      specify the self control port(*)
  -no_giveup_rejoin    not give up rejoining chmpx
  -comlog              enable logging communication command
  -d <param>           specify the debugging output mode:
                        silent - no output
                        err    - output error level
                        wan    - output warning level
                        msg    - output debug(message) level
                        dump   - output communication debug level
  -dfile <path>        specify the file path which is put output
  -h(help)             display this usage.
  -v(version)          display version.

[environment]
  K2HDKCCONFFILE       specify the configuration file(.ini .yaml .json) path
  K2HDKCJSONCONF       specify the configuration json string

(*) you can use environment DKCDBGMODE and DKCDBGFILE instead of -d/-dfile options.
(*) if ctlport option is specified, chmpx searches same ctlport in configuration
    file and ignores "CTLPORT" directive in "GLOBAL" section. and chmpx will
    start in the mode indicated by the server entry that has been detected.
```