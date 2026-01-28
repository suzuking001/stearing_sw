# stearing_sw

BLEキーボードとして動作する自作ステアリング（スイッチ）用のArduino/ESP32スケッチです。  
アナログ入力（可変抵抗やロータリースイッチ等）の値に応じて、音量/再生操作やショートカットを送信します。

## できること（概要）
- BLEキーボードとしてPC/タブレットに接続
- 3系統のアナログ入力（A0/A3/A6）を読み取り
- 指定レンジに入ったらメディア操作・ショートカットを送信
- LEDで入力検知を可視化（pin 12）

## 前提環境
- Arduino IDE（またはPlatformIO）
- ESP32 系ボード（BleKeyboardライブラリ対応が必要）
- BleKeyboard ライブラリ

## 配線（現行コード）
- A0: `sensorPin1`（アナログ入力1）
- A3: `sensorPin2`（アナログ入力2）
- A6: `sensorPin3`（3.3V監視/アナログ入力3）
- D12: `ledPin`（LED）

※ A6で3.3V低下チェック（`sensorValue3 < 3000`）を行い、低下時はLEDを点灯しつつ `sensorValue1=2640` に固定します。

## 使い方
1) Arduino IDEで `prg/stsw/stsw.ino` を開く  
2) ESP32用のボード設定を行う  
3) BleKeyboardライブラリを導入する  
4) 書き込み後、BLEキーボードとしてペアリング  
5) 各入力が指定レンジに入るとキー入力が送信される

## 操作一覧（アナログ値の中心と割当）
※ 許容範囲は `setValue ± pitch`（pitch=200）  
※ 値は目安。実機で校正してください

### A3（sensorValue2）
- 1080: VOLUME_UP
- 1605: VOLUME_DOWN
- 2645: NEXT_TRACK
- 3235: PREVIOUS_TRACK
- 2128: HOME（メディアホーム）
- 575 : PLAY_PAUSE

### A0（sensorValue1）
- 1605: パスワード入力（固定値 "249666" を送信）
- 570 : アプリ切替（Cmd + Tab）
- 2640: 画面ロック（Cmd + Ctrl + q）

### A6（sensorValue3）
- 3000 未満: 3.3V低下判定（LED点灯、`sensorValue1=2640` に固定）

## 注意点
- **パスワードがコード内にハードコードされています**。用途に応じて削除/変更してください。
- 入力がレンジ内にいる間は一定間隔で連続送信される操作があります（例: VOLUME_UP/DOWN）。  
  意図しない連打が起きる場合は条件や `delay` を調整してください。
- `setValue` が重複する入力（例: `1605` 付近）は同時発火の可能性があります。必要に応じて整理してください。

## メモ（現行ロジック）
- 起動直後、BLE接続後に 1.5 秒待機し `sensorValue1=1605` を一度だけセットします。
- LEDは入力検知時に点灯し、最後に消灯します。

## ファイル構成
- `prg/stsw/stsw.ino` : メインスケッチ
- `excel/*.xlsx` : 回路・キーボードメモ
- `stl/*.stl` : ケースCADデータ

## 変更したい場合
- キー割当は `setValue` と `bleKeyboard.press/print` を編集してください
- アナログの閾値は `pitch` で調整可能です
