# glibcのライブラリ関数を上書きする実験用

BINARY HACKのHACK 60、61を真似て、printfを上書きするテスト

## 使い方
printfを使う適当なコードをコンパイルして、以下のように実行すると偽のprintfが実行される
```
LD\_PRELOAD=/path/to/libfake.so ./a.out
```
