# USB_Host_Shield_Library_2.0_BTSSP_b
The code is released under the GNU General Public License.

## Summary
This library is based on the USB Host Shield Library 2.0 with modifications to support Secure Simple Pairing on Bluetooth to use the Microsoft Game Controller (for Xbox One S/Windows MODEL 1708).

## 概要
これは過去に USB Host Shield Library 2.0 を元にして Microsoftゲームコントローラー（Xbox One S/Windows用 MODEL 1708）が繋がるように、ライブラリのBluetoothの部分を Secure Simple Pairing 対応に改造した USB_Host_Shield_Library_2.0_BTSSP を、更に改造した作りかけのライブラリです。
USB_Host_Shield_2.0 と USB_Host_Shield_Library_2.0_BTSSP については下記を参照してください。

USB_Host_Shield_2.0 リポジトリ  
<http://github.com/felis/USB_Host_Shield_2.0>  
プロジェクトサイト   
<https://chome.nerpa.tech/arduino_usb_host_shield_projects/>

USB_Host_Shield_Library_2.0_BTSSP リポジトリ  
<https://github.com/HisashiKato/USB_Host_Shield_Library_2.0_BTSSP>  

次の機能を追加する準備のために大幅な変更を加えたので、別リポジトリにしました。不具合やバグ、エラーが増えています。特に Disconnect でエラーが出ます。
動作保証はしません。ユーザーサポートもしません。使用は自己責任で。何か問題があっても自分で何とかしてください。

商用のプログラムのコード等は書いたことが無い素人で初心者なので、絶対に色々と間違っています。
このライブラリのソースコードを、プロの人やC++の熟練者が見ると「なんでこんなコードの書き方をするんだよ！」と怒りさえ覚える人がいるかもしれません。
もし居ましたら、このライブラリをフォークして、添削や清書をして頂ければと思います。

オープンソースなので、ライセンスの範囲内で自由に使ってやってください。


USB_Host_Shield_Library_2.0_BTSSP_b リポジトリ  
<https://github.com/HisashiKato/USB_Host_Shield_Library_2.0_BTSSP_b>  

　  

## ハードウェア
* Arduino 及び、その互換機（但し、Arduino の EEPROMライブラリ が使えるボードのみ）  
* USB Host Shield　2.0  
* Bluetooth 4.0 USBアダプタ

   
   

## 使用方法
### Arduino IDE にライブラリを組み込む  
USB Host Library Rev.2.0 BTSSPは、Arduino IDEで使用できます。
    
1. Code の Download ZIP 、または下記URLから、ライブラリのZIPをダウンロードします。  
<https://github.com/HisashiKato/USB_Host_Shield_Library_2.0_BTSSP_b/archive/master.zip>  
   
2. Arduino IDE を起動して、スケッチ > ライブラリをインクルード > .ZIP形式のライブラリをインストール で、ダウンロードした USB_Host_Shield_Library_2.0_BTSSP_b-master.zip を指定します。  
   
3. Arduino IDE に、「ライブラリが追加されました。「ライブラリをインクルード」メニューを確認してください。」と表示されれば成功。

4. Arduino IDE で、メニューの スケッチ > ライブラリをインクルード のライブラリの一覧に、USB Host Shield Library 2.0 BTSSP が表示されているのを確認してください。

   
   
   
### ライブラリの使用方法
先ずは、元の USB Host Library Rev.2.0 のライブラリの使用方法を読んでください。

基本的には USB_Host_Shield_Library_2.0_BTSSP と同じです。具体的な使い方は、スケッチ例を参照してください。

  
   

## 対応コントローラー

### Microsoftゲームコントローラー（Xbox One S/Windows用 MODEL 1708）

コントローラーの基本の情報の受信に加えて、振動用データの送信に対応しました。

ゲームコントローラーのファームウェアが違うと、通信の仕様や送られてくるデータが異なります。過去に動作確認を行ったコントローラーのファームウェアは、ライブラリ製作時の 4.8.1923.0 です。使用するコントローラーのファームウェアを確認してください。

ファームウェアを最新の "5.13.3143.0" にアップデートをしたら、そのコントローラーが、このライブラリで使えなくなりました。5.13.3143.0 で、Bluetooth Classic から Bluetooth Low Energy (BLE) に変更されたためです。このライブラリは BLE 未実装です。

ファームウェアをダウングレード(ロールバック)する方法を探しました。古い 3.1.1221.0 に戻す方法は見つかりました。

"My Xbox controller has connection issues after the last update"
https://support.xbox.com/en-US/help/hardware-network/accessories/controller-firmware-reversion

しかし、4.8.1923.0 に戻す方法は見つかりませんでした。

そこで、3.1.1221.0 のボタンの読み取りを追加しました。3.1.1221.0 ではチェックをしましたが、4.8.1923.0 ではチェックをしていません。

### Nintendo Switch Pro コントローラー

簡易版です。サブコマンドの送信を組み込んだので、振動を暫定的に入れてみました。ジャイロは対応するか未定です。Disconnect でエラーが出ます。

### SONY DUALSHOCK 4 コントローラー

オリジナルの USB Host Library 2.0 の、DUALSHOCK 4 の関数群を移植しました。Disconnect でエラーが出ます。

### Bluetooth キーボード,マウス

所有しているBluetoothキーボードとBluetoothマウスで、SSPでのペアリングと、ペアリング後の接続と入力が出来ました。最近、セキュリティのリスクを減らすために、オリジナルのライブラリで使用している4ケタの固定のPINコードを使う古いペアリングのモードではペアリングが働かない（ボンディングが行われない）Bluetoothキーボードがあるみたいです。
そのようなキーボードやマウスは、このライブラリなら使用できる可能性があります。

## 参考にさせて頂いたプロジェクトやWEBサイト
<https://github.com/felis/USB_Host_Shield_2.0>：USB_Host_Shield_2.0 の本家

<https://www.silex.jp/blog/wireless/>：サイレックス・テクノロジー株式会社 のblog、Wireless・のおと（Bluetoothの基本）

<http://www.yts.rdy.jp/pic/GB002/GB002.html>：YTSさんの、YTSのホームページ（SSPの詳細等）

<https://hackaday.io/project/170365-blueretro>：Jacques Gagnon 氏の"BlueRetro"（とても参考になりました！！！）

<https://github.com/atar-axis/xpadneo>：Advanced Linux Driver for Xbox One Wireless Gamepad

<https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering>：Nintendo_Switch_Reverse_Engineering

その他、思いついたら追加します。
こうして作ることが出来たのも、みなさんのおかげです。本当にありがとうございます。
