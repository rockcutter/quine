# quine
## 概要
このプログラムは、rockcutterっぽい形に成形された、quineです
> クワイン（英: Quine）は、コンピュータープログラムの一種で、自身のソースコードと完全に同じ文字列を出力するプログラムである。
   [wikipedia](https://ja.wikipedia.org/wiki/%E3%82%AF%E3%83%AF%E3%82%A4%E3%83%B3_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)) より

## 実行方法
```bash
git clone https://github.com/rockcutter/quine.git
cd quine
make
./quine

#比較する
./quine > hoge.cpp
diff -s rockcutter.cpp hoge.cpp

#コンパイル成果物を消す
make clean

#シェルスクリプトを使う
./CompileAndCheck.sh
```
