# 2026-10-12 程式檢查修正

本分支根據三本 Global Edition 教材、repository 內的課程講義與 README，修正已確認的程式結果、記憶體與輸入處理錯誤。以各份獨立作業為單位保留原有目錄，沒有把相同名稱的不同課程類別合併。

## 修正內容

- C：BMI 25/30 邊界、逐位輸出、Newton 迭代限制、真正呼叫質數／回文函式、費用 helper、含正負號與小數的 FSM、每列座標及質量讀取、UPC 輸出、二分搜尋計數、kΩ 單位、略過標點的回文與迷宮起點；補上缺少的範例輸入檔及必要讀檔檢查。
- C++：金額 double、POSTNET 碼表與輸入驗證、空直方圖、MyInteger 輸入參照及 0 位數、PrimeNumber postfix 舊值、Complex const 輸出、四字母詞分隔、隨機蔬果、Television copy construction／深拷貝、Student assignment 回傳值、Creature 傷害呼叫鏈與單次 seed、缺少的 accessor/mutator 與本地 header 路徑。
- Java：價格驗證、讀完五筆後輸出長條圖、70 欄賽道、Poker 同牌型點數及 kicker、A2345 順子、攻擊目標與傷害表、依缺少生命／魔力選藥、Practice4 繼承的藥物功能，以及繪圖程式在事件中更新座標而不是在 paint 中修改資料。
- Web：合法標題嵌套、空統計及取消輸入、抽牌完成音效、計算機 C／等號、配對遊戲 Restart 舊 timer、分開搜尋與成績儲存的 key 範圍、DOM 安全呈現及資料驗證；PHP 圖片大小寫、日期與身高體重檢查。
- 演算法：取模前乘法溢位、PT2 表耗尽與檢查順序、平方界限、增加至 1000000 的 sieve、隨機底數範圍、可執行的四種演算法計時及合數誤判次數實驗，以及 exponent ≤ 61 的 Lucas–Lehmer 梅森質數搜尋。

重心範例的正確數值是 **(1.3, 0.9, 0.0)**。先前 review 報告的預期數值有筆誤，已更正；每列 `x y z mass` 的讀取修正本身是必要的。

## 執行驗證

需要 Python 3、GCC、G++、Java 17（或支援目前語法的 JDK）與 Node.js：

```bash
python3 -m unittest discover -s tests -v
```

測試會在暫存目錄編譯 47 個 C/C++/演算法單位及 15 個 Java 單位，不在作業目錄放編譯產物。回歸案例包含全部 100000 個五位 ZIP code、重心／電阻／BMI 邊界、TV 深拷貝與 self-assignment、Java 六個戰鬥版本、同牌型比較、Restart 過期 callback、跨頁儲存隔離、大整數模冪與已知梅森質數。

記憶體 probe 使用 AddressSanitizer 與 UndefinedBehaviorSanitizer。若執行環境使用 ptrace 且不允許 LeakSanitizer 讀取 `/proc`，可用：

```bash
ASAN_OPTIONS=detect_leaks=0 python3 -m unittest discover -s tests -v
```

這只停用 leak detection，越界／use-after-free／UB 檢查仍開啟。本次受限環境使用此方式驗證，不宣稱已完成 leak 檢查。

## 質數程式使用

```bash
gcc -std=c11 -O2 3-1/algo/1/S11359016/code/Prime_Prog_S11359016.c -o prime
./prime
./prime --benchmark
./prime --mersenne
```

`--benchmark` 輸出實際測量 CSV，100 次重複取平均；sieve 建表成本另外列出，超出表上界的 query 標為 N/A。Carmichael 合數的兩種隨機測試各做 1000 次，報告「實驗誤判次数」，不把有限樣本誤判为 0 視為數學保證。`PT2` 超出固定 prime table 可判定的範圍時回傳 -1，代表無法判定；Fermat／Miller–Rabin 的 1 表示 probable prime。大於 10^12 不跑昂貴的 trial division。梅森搜尋明訂範圍，不聲稱找到世界紀錄。

## 保留事項

- `Clock` 教材的「all three」「and」重設規則有歧義。本次只修時間补零，未替老師決定 setter 驗證語義。
- 05/26 三個網頁題及 06/02 PHP 缺完整題目。本次只修可確認的程式問題，不宣稱完成未知作業要求。舊的裸 localStorage key 仍保留，不擅自刪除或猜測遷移；新版本各自使用命名空間。
- GUI 已編譯並檢查事件邏輯，沒有實際桌面滑鼠測試；前端測試使用 Node VM，不驗證瀏覽器像素排版或自動播放政策。開頁音效可能由瀏覽器阻擋，使用者按 shuffle 後才可播放。
- 環境未提供 PHP runtime，PHP 僅靜態檢查，部署前可執行 `php -l 2-2/20260602/index.php` 及表單測試。
- 原本的 DOCX 報告、ZIP、exe/out 提交產物沒有偽造更新。報告仍須依新程式重跑實驗、補理論與格式，ZIP／執行檔須重新產生。
- 部分原題要求的「測試所有 accessor／mutator」或特定作業呈現方式仍應按課程標準補足。本分支不是老師的完整作業評分或所有輸入的形式證明。
