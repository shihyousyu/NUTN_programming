<!DOCTYPE html>
<html lang="zh-TW">
<head>
    <meta charset="UTF-8">
</head>
<body>

<div align="center">
    <div class="form-section">
        <form method="POST" action="">
            <label>生日：</label>
            <select name="year">
                <?php for($i=2024; $i>=1970; $i--) echo "<option value='$i'>$i</option>"; ?>
            </select> 年
            <select name="month">
                <?php for($i=1; $i<=12; $i++) echo "<option value='$i'>$i</option>"; ?>
            </select> 月
            <select name="day">
                <?php for($i=1; $i<=31; $i++) echo "<option value='$i'>$i</option>"; ?>
            </select> 日
            <br><br>
            <label>身高：</label>
            <input type="number" name="height" step="0.1" required> 公分
            <br><br>
            <label>體重：</label>
            <input type="number" name="weight" step="0.1" required> 公斤
            <br><br>
            <input type="submit" value="提交">
        </form>
    </div>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $y = intval($_POST['year']);
        $m = intval($_POST['month']);
        $d = intval($_POST['day']);
        $h_cm = floatval($_POST['height']);
        $w_kg = floatval($_POST['weight']);

        function getZodiacName($month, $day) {
            if (($month == 3 && $day >= 21) || ($month == 4 && $day <= 19)) return "牡羊座";
            if (($month == 4 && $day >= 20) || ($month == 5 && $day <= 20)) return "金牛座";
            if (($month == 5 && $day >= 21) || ($month == 6 && $day <= 21)) return "雙子座";
            if (($month == 6 && $day >= 22) || ($month == 7 && $day <= 22)) return "巨蟹座";
            if (($month == 7 && $day >= 23) || ($month == 8 && $day <= 22)) return "獅子座";
            if (($month == 8 && $day >= 23) || ($month == 9 && $day <= 22)) return "處女座";
            if (($month == 9 && $day >= 23) || ($month == 10 && $day <= 23)) return "天秤座";
            if (($month == 10 && $day >= 24) || ($month == 11 && $day <= 22)) return "天蠍座";
            if (($month == 11 && $day >= 23) || ($month == 12 && $day <= 21)) return "射手座";
            if (($month == 12 && $day >= 22) || ($month == 1 && $day <= 19)) return "摩羯座";
            if (($month == 1 && $day >= 20) || ($month == 2 && $day <= 18)) return "水瓶座";
            return "雙魚座";
        }
        $zodiac = getZodiacName($m, $d);

        $zodiacImages = [
            "牡羊座" => "aries.png", "金牛座" => "taurus.png", "雙子座" => "gemini.png",
            "巨蟹座" => "cancer.png", "獅子座" => "leo.png", "處女座" => "virgo.png",
            "天秤座" => "libra.png", "天蠍座" => "scorpio.png", "射手座" => "sagittarius.png",
            "摩羯座" => "capricorn.png", "水瓶座" => "aquarius.png", "雙魚座" => "pisces.png"
        ];
        $imgUrl = $zodiacImages[$zodiac];

        $dateStr = "$y-$m-$d";
        $isLeap = (date("L", strtotime($dateStr)) == 1) ? "當年為閏年" : "當年不為閏年";
        $weekMap = ["Sunday"=>"星期日","Monday"=>"星期一","Tuesday"=>"星期二","Wednesday"=>"星期三","Thursday"=>"星期四","Friday"=>"星期五","Saturday"=>"星期六"];
        $dayOfWeek = $weekMap[date("l", strtotime($dateStr))];

        $h_m = $h_cm / 100;
        $bmi = $w_kg / ($h_m * $h_m);
        $comment = ($bmi < 18.5) ? "體重過輕" : (($bmi < 24) ? "剛剛好，繼續保持下去喔" : "體重過重");
    ?>

    <div class="result-section" style="width: 80%;">
        <h2 align="left">Result:</h2>
        <p align="left">執行結果</p>
        
        <br>
        <p><b>星座</b></p>
        <img src="<?= $imgUrl ?>" width="150" alt="<?= $zodiac ?>">
        <p><font size="2"><?= $zodiac ?></font></p>
        <br>

        <p><b>閏年</b></p>
        <p><font size="2"><?= $isLeap ?></font></p>
        <br>

        <p><b>當日星期(<?= "$y/$m/$d" ?>)</b></p>
        <p><font size="2"><?= $dayOfWeek ?></font></p>
        <br>

        <p><b>BMI</b></p>
        <p><font size="2"><?= $bmi ?></font></p>
        <br>

        <p><b>評語</b></p>
        <p><font size="2"><?= $comment ?></font></p>
    </div>
    <?php } ?>
</div>

</body>
</html>