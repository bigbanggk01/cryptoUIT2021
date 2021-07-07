-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Máy chủ: 127.0.0.1
-- Thời gian đã tạo: Th7 07, 2021 lúc 07:20 AM
-- Phiên bản máy phục vụ: 10.4.19-MariaDB
-- Phiên bản PHP: 8.0.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Cơ sở dữ liệu: `blog`
--

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `comments`
--

CREATE TABLE `comments` (
  `id` int(11) NOT NULL,
  `post_id` int(11) NOT NULL,
  `comment` text NOT NULL,
  `username` varchar(255) CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `comments`
--

INSERT INTO `comments` (`id`, `post_id`, `comment`, `username`) VALUES
(13, 0, '28', 'tudeptrai222'),
(14, 28, 'sadsadsadsadas', 'tudeptrai222'),
(15, 28, '\'\'\'\'\'\'#', 'tudeptrai222'),
(16, 29, 'test comment', 'nickmoitao');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `posts`
--

CREATE TABLE `posts` (
  `id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `topic_id` int(11) DEFAULT NULL,
  `title` varchar(255) NOT NULL,
  `image` varchar(255) NOT NULL,
  `body` text NOT NULL,
  `published` tinyint(4) NOT NULL,
  `created_at` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Đang đổ dữ liệu cho bảng `posts`
--

INSERT INTO `posts` (`id`, `user_id`, `topic_id`, `title`, `image`, `body`, `published`, `created_at`) VALUES
(27, 54, 5, 'Rasberry Pi 4 - Mini Module But Powerful', '1625606631_Raspi-PGB001.png', '&lt;p&gt;&lt;strong&gt;Raspberry Pi&lt;/strong&gt; (&lt;a href=&quot;https://en.wikipedia.org/wiki/Help:IPA/English&quot;&gt;/paɪ/&lt;/a&gt;) is a series of small &lt;a href=&quot;https://en.wikipedia.org/wiki/Single-board_computer&quot;&gt;single-board computers&lt;/a&gt; (SBCs) developed in the &lt;a href=&quot;https://en.wikipedia.org/wiki/United_Kingdom&quot;&gt;United Kingdom&lt;/a&gt; by the &lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi_Foundation&quot;&gt;Raspberry Pi Foundation&lt;/a&gt; in association with &lt;a href=&quot;https://en.wikipedia.org/wiki/Broadcom_Inc.&quot;&gt;Broadcom&lt;/a&gt;.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-15&quot;&gt;[15]&lt;/a&gt; The Raspberry Pi project originally leaned towards the promotion of teaching basic &lt;a href=&quot;https://en.wikipedia.org/wiki/Computer_science&quot;&gt;computer science&lt;/a&gt; in schools and in &lt;a href=&quot;https://en.wikipedia.org/wiki/Developing_countries&quot;&gt;developing countries&lt;/a&gt;.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-16&quot;&gt;[16]&lt;/a&gt;&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-17&quot;&gt;[17]&lt;/a&gt;&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-18&quot;&gt;[18]&lt;/a&gt; The original model became more popular than anticipated,&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-1000x-19&quot;&gt;[19]&lt;/a&gt; selling outside its &lt;a href=&quot;https://en.wikipedia.org/wiki/Target_market&quot;&gt;target market&lt;/a&gt; for uses such as &lt;a href=&quot;https://en.wikipedia.org/wiki/Robotics&quot;&gt;robotics&lt;/a&gt;. It is widely used in many areas, such as for weather monitoring,&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-20&quot;&gt;[20]&lt;/a&gt; because of its low cost, modularity, and open design. It is typically used by computer and electronic hobbyists, due to its adoption of HDMI and USB devices.&lt;/p&gt;&lt;p&gt;After the release of the second board type, the Raspberry Pi Foundation set up a new entity, named Raspberry Pi Trading, and installed &lt;a href=&quot;https://en.wikipedia.org/wiki/Eben_Upton&quot;&gt;Eben Upton&lt;/a&gt; as &lt;a href=&quot;https://en.wikipedia.org/wiki/Chief_executive_officer&quot;&gt;CEO&lt;/a&gt;, with the responsibility of developing technology.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-21&quot;&gt;[21]&lt;/a&gt; The Foundation was rededicated as an educational charity for promoting the teaching of basic computer science in schools and developing countries.&lt;/p&gt;&lt;p&gt;Sold units of the Raspberry Pi&lt;/p&gt;&lt;p&gt;The Raspberry Pi is one of the best-selling &lt;a href=&quot;https://en.wikipedia.org/wiki/British_computer&quot;&gt;British computers&lt;/a&gt;.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-bestseller-22&quot;&gt;[22]&lt;/a&gt; As of May 2021, more than forty million boards have been sold.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-thirtymillion-23&quot;&gt;[23]&lt;/a&gt; Most Pis are made in a &lt;a href=&quot;https://en.wikipedia.org/wiki/Sony&quot;&gt;Sony&lt;/a&gt; factory in &lt;a href=&quot;https://en.wikipedia.org/wiki/Pencoed&quot;&gt;Pencoed&lt;/a&gt;, Wales,&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-24&quot;&gt;[24]&lt;/a&gt; while others are made in China and Japan.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-25&quot;&gt;[25]&lt;/a&gt;&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-26&quot;&gt;[26]&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Generation&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Several generations of Raspberry Pis have been released. Raspberry Pi SBCs feature a &lt;a href=&quot;https://en.wikipedia.org/wiki/Broadcom&quot;&gt;Broadcom&lt;/a&gt; &lt;a href=&quot;https://en.wikipedia.org/wiki/System_on_a_chip&quot;&gt;system on a chip&lt;/a&gt; (SoC) with an integrated &lt;a href=&quot;https://en.wikipedia.org/wiki/ARM_architecture&quot;&gt;ARM&lt;/a&gt;-compatible &lt;a href=&quot;https://en.wikipedia.org/wiki/Central_processing_unit&quot;&gt;central processing unit&lt;/a&gt; (CPU) and &lt;a href=&quot;https://en.wikipedia.org/wiki/Graphics_processing_unit#Integrated_graphics&quot;&gt;on-chip graphics processing unit&lt;/a&gt; (GPU), while Raspberry Pi Pico has a &lt;a href=&quot;https://en.wikipedia.org/wiki/RP2040&quot;&gt;RP2040&lt;/a&gt; system on chip with an integrated &lt;a href=&quot;https://en.wikipedia.org/wiki/ARM_architecture&quot;&gt;ARM&lt;/a&gt;-compatible &lt;a href=&quot;https://en.wikipedia.org/wiki/Central_processing_unit&quot;&gt;central processing unit&lt;/a&gt; (CPU).&lt;/p&gt;&lt;p&gt;The first generation (&lt;strong&gt;Raspberry Pi&amp;nbsp;Model&amp;nbsp;B&lt;/strong&gt;) was released in February 2012, followed by the simpler and cheaper &lt;strong&gt;Model&amp;nbsp;A&lt;/strong&gt;. In 2014, the Foundation released a board with an improved design, &lt;strong&gt;Raspberry Pi&amp;nbsp;Model&amp;nbsp;B+&lt;/strong&gt;. These first generation boards feature &lt;a href=&quot;https://en.wikipedia.org/wiki/ARM11&quot;&gt;ARM11 processors&lt;/a&gt;, are approximately credit-card sized and represent the standard &lt;i&gt;mainline&lt;/i&gt; form-factor. Improved A+ and B+ models were released a year later.[&lt;a href=&quot;https://en.wikipedia.org/wiki/Wikipedia:Please_clarify&quot;&gt;&lt;i&gt;clarification needed&lt;/i&gt;&lt;/a&gt;] A &lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#Compute_module&quot;&gt;&quot;Compute Module&quot;&lt;/a&gt; was released in April 2014 for &lt;a href=&quot;https://en.wikipedia.org/wiki/Embedded_system&quot;&gt;embedded applications&lt;/a&gt;.&lt;/p&gt;&lt;p&gt;The &lt;strong&gt;Raspberry Pi&amp;nbsp;2&lt;/strong&gt; was released in February 2015 and initially featured a 900&amp;nbsp;MHz 32-bit quad-core &lt;a href=&quot;https://en.wikipedia.org/wiki/ARM_Cortex-A7&quot;&gt;ARM Cortex-A7&lt;/a&gt; processor with 1 GB RAM. Later versions featured a 1.2&amp;nbsp;GHz &lt;a href=&quot;https://en.wikipedia.org/wiki/64-bit_computing&quot;&gt;64-bit&lt;/a&gt; quad-core &lt;a href=&quot;https://en.wikipedia.org/wiki/ARM_Cortex-A53&quot;&gt;ARM Cortex-A53&lt;/a&gt; processor.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-:0-27&quot;&gt;[27]&lt;/a&gt;&lt;/p&gt;&lt;p&gt;A &lt;strong&gt;Raspberry Pi&amp;nbsp;Zero&lt;/strong&gt; with smaller size and reduced &lt;a href=&quot;https://en.wikipedia.org/wiki/Input/output&quot;&gt;input/output&lt;/a&gt; (I/O) and &lt;a href=&quot;https://en.wikipedia.org/wiki/General-purpose_input/output&quot;&gt;general-purpose input/output&lt;/a&gt; (GPIO) capabilities was released in November 2015 for US$5. On 28 February 2017, the &lt;strong&gt;Raspberry Pi Zero&amp;nbsp;W&lt;/strong&gt; was launched, a version of the Zero with Wi-Fi and Bluetooth capabilities, for US$10.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-28&quot;&gt;[28]&lt;/a&gt;&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-29&quot;&gt;[29]&lt;/a&gt; On 12 January 2018, the &lt;strong&gt;Raspberry Pi Zero&amp;nbsp;WH&lt;/strong&gt; was launched, a version of the Zero W with pre-soldered GPIO headers.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-30&quot;&gt;[30]&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Raspberry Pi&amp;nbsp;3 Model&amp;nbsp;B&lt;/strong&gt; was released in February 2016 with a 1.2&amp;nbsp;GHz 64-bit &lt;a href=&quot;https://en.wikipedia.org/wiki/Multi-core_processor&quot;&gt;quad core&lt;/a&gt; &lt;a href=&quot;https://en.wikipedia.org/wiki/ARM_Cortex-A53&quot;&gt;ARM Cortex-A53&lt;/a&gt; processor, on-board &lt;a href=&quot;https://en.wikipedia.org/wiki/802.11n&quot;&gt;802.11n&lt;/a&gt; &lt;a href=&quot;https://en.wikipedia.org/wiki/Wi-Fi&quot;&gt;Wi-Fi&lt;/a&gt;, &lt;a href=&quot;https://en.wikipedia.org/wiki/Bluetooth&quot;&gt;Bluetooth&lt;/a&gt; and USB boot capabilities.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-31&quot;&gt;[31]&lt;/a&gt; On &lt;a href=&quot;https://en.wikipedia.org/wiki/Pi_Day&quot;&gt;Pi Day&lt;/a&gt; 2018, the &lt;strong&gt;Raspberry Pi&amp;nbsp;3 Model&amp;nbsp;B+&lt;/strong&gt; was launched with a faster 1.4&amp;nbsp;GHz processor, a three-times faster &lt;a href=&quot;https://en.wikipedia.org/wiki/Gigabit_Ethernet&quot;&gt;gigabit Ethernet&lt;/a&gt; (throughput limited to ca. 300&amp;nbsp;&lt;a href=&quot;https://en.wikipedia.org/wiki/Mbit/s&quot;&gt;Mbit/s&lt;/a&gt; by the internal USB&amp;nbsp;2.0 connection), and 2.4 / 5&amp;nbsp;GHz &lt;a href=&quot;https://en.wikipedia.org/wiki/Dual-band&quot;&gt;dual-band&lt;/a&gt; &lt;a href=&quot;https://en.wikipedia.org/wiki/802.11ac&quot;&gt;802.11ac&lt;/a&gt; Wi-Fi (100 Mbit/s).&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-RapsberryPi3B+Release-32&quot;&gt;[32]&lt;/a&gt; Other features are &lt;a href=&quot;https://en.wikipedia.org/wiki/Power_over_Ethernet&quot;&gt;Power over Ethernet&lt;/a&gt; (PoE) (with the add-on PoE &lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#Accessories&quot;&gt;HAT&lt;/a&gt;), &lt;a href=&quot;https://en.wikipedia.org/wiki/USB-bootable_Linux_distribution&quot;&gt;USB boot&lt;/a&gt; and &lt;a href=&quot;https://en.wikipedia.org/wiki/Network_booting&quot;&gt;network boot&lt;/a&gt; (an &lt;a href=&quot;https://en.wikipedia.org/wiki/SD_card&quot;&gt;SD card&lt;/a&gt; is no longer required).&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Raspberry Pi&amp;nbsp;4 Model&amp;nbsp;B&lt;/strong&gt; was released in June 2019&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-Pi4OnSale-2&quot;&gt;[2]&lt;/a&gt; with a 1.5&amp;nbsp;GHz 64-bit quad core &lt;a href=&quot;https://en.wikipedia.org/wiki/ARM_Cortex-A72&quot;&gt;ARM Cortex-A72&lt;/a&gt; processor, on-board 802.11ac &lt;a href=&quot;https://en.wikipedia.org/wiki/Wi-Fi&quot;&gt;Wi-Fi&lt;/a&gt;, &lt;a href=&quot;https://en.wikipedia.org/wiki/Bluetooth_5&quot;&gt;Bluetooth 5&lt;/a&gt;, full &lt;a href=&quot;https://en.wikipedia.org/wiki/Gigabit_Ethernet&quot;&gt;gigabit Ethernet&lt;/a&gt; (throughput not limited), two &lt;a href=&quot;https://en.wikipedia.org/wiki/USB_2.0&quot;&gt;USB 2.0&lt;/a&gt; ports, two &lt;a href=&quot;https://en.wikipedia.org/wiki/USB_3.0&quot;&gt;USB 3.0&lt;/a&gt; ports, and dual-monitor support via a pair of micro HDMI (&lt;a href=&quot;https://en.wikipedia.org/wiki/HDMI#Connectors&quot;&gt;HDMI Type D&lt;/a&gt;) ports for up to &lt;a href=&quot;https://en.wikipedia.org/wiki/4K_resolution&quot;&gt;4K resolution&lt;/a&gt;. The Pi 4 is also powered via a &lt;a href=&quot;https://en.wikipedia.org/wiki/USB-C&quot;&gt;USB-C&lt;/a&gt; port, enabling additional power to be provided to downstream peripherals, when used with an appropriate PSU. The initial Raspberry Pi 4 board has a design flaw where third-party &lt;a href=&quot;https://en.wikipedia.org/wiki/USB-C#Cables&quot;&gt;e-marked&lt;/a&gt; USB cables, such as those used on Apple MacBooks, incorrectly identify it and refuse to provide power.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-33&quot;&gt;[33]&lt;/a&gt;&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-34&quot;&gt;[34]&lt;/a&gt; &lt;a href=&quot;https://en.wikipedia.org/wiki/Tom%27s_Hardware&quot;&gt;Tom\'s Hardware&lt;/a&gt; tested 14 different cables and found that 11 of them turned on and powered the Pi without issue.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-35&quot;&gt;[35]&lt;/a&gt; The design flaw was fixed in revision 1.2 of the board, released in late 2019.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-36&quot;&gt;[36]&lt;/a&gt;&lt;/p&gt;&lt;p&gt;Raspberry Pi 400 Kit&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Raspberry Pi 400&lt;/strong&gt; was released in November 2020. It features a custom board that is derived from the existing Raspberry Pi 4, specifically remodelled with a keyboard attached. A robust cooling solution similar to the one found in a Commodore 64 allows the Raspberry Pi 400\'s Broadcom BCM2711C0 processor to be clocked at 1.8&amp;nbsp;GHz, which is slightly higher than the Raspberry Pi 4 it\'s based on.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-37&quot;&gt;[37]&lt;/a&gt; The keyboard-computer features 4 GB of LPDDR4 RAM.&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Raspberry Pi Pico&lt;/strong&gt; was released in January 2021 with a retail price of $4.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-38&quot;&gt;[38]&lt;/a&gt; It was Raspberry Pi\'s first board based upon a single &lt;a href=&quot;https://en.wikipedia.org/wiki/Microcontroller&quot;&gt;microcontroller&lt;/a&gt; chip; the RP2040, which was designed by Raspberry Pi in the UK.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-39&quot;&gt;[39]&lt;/a&gt; The Pico has 264 KB of RAM and 2 MB of &lt;a href=&quot;https://en.wikipedia.org/wiki/Flash_memory&quot;&gt;flash memory&lt;/a&gt;. It is programmable in &lt;a href=&quot;https://en.wikipedia.org/wiki/MicroPython&quot;&gt;MicroPython&lt;/a&gt;, &lt;a href=&quot;https://en.wikipedia.org/wiki/CircuitPython&quot;&gt;CircuitPython&lt;/a&gt;, and &lt;a href=&quot;https://en.wikipedia.org/wiki/C_(programming_language)&quot;&gt;C&lt;/a&gt;. It has partnered with &lt;a href=&quot;https://en.wikipedia.org/wiki/Adafruit_Industries&quot;&gt;Adafruit&lt;/a&gt;, &lt;a href=&quot;https://en.wikipedia.org/wiki/Pimoroni&quot;&gt;Pimoroni&lt;/a&gt;, &lt;a href=&quot;https://en.wikipedia.org/wiki/Arduino&quot;&gt;Arduino&lt;/a&gt; and &lt;a href=&quot;https://en.wikipedia.org/wiki/SparkFun_Electronics&quot;&gt;SparkFun&lt;/a&gt; to build Accessories for Raspberry Pi Pico and variety of other boards using RP2040 Silicon Platform.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-:1-40&quot;&gt;[40]&lt;/a&gt; Rather than perform the role of general purpose computer (like the others in the range) it is designed for &lt;a href=&quot;https://en.wikipedia.org/wiki/Physical_computing&quot;&gt;physical computing&lt;/a&gt;, similar in concept to an &lt;a href=&quot;https://en.wikipedia.org/wiki/Arduino&quot;&gt;Arduino&lt;/a&gt;.&lt;a href=&quot;https://en.wikipedia.org/wiki/Raspberry_Pi#cite_note-41&quot;&gt;[41]&lt;/a&gt;&lt;/p&gt;', 1, '2021-07-07 04:23:51'),
(28, 54, 3, 'StarCraft II - THE ULTIMATE REAL-TIME STRATEGY GAME', '1625606780_Untitled.png', '&lt;p&gt;The basics&lt;/p&gt;&lt;p&gt;Starcraft 2 is a very complicated game, it\'s very in-depth and has a steep learning curve. But please don\'t let that intimidate you from trying to understand everything. Everyone started somewhere in this subreddit, and no matter what we\'ll try to help you to the best of our ability.&lt;/p&gt;&lt;p&gt;Before you start a game, you can pick a race from the 3 that are available. You have &lt;a href=&quot;https://www.youtube.com/watch?v=Fmu8PsUDDtQ&quot;&gt;Terran&lt;/a&gt;, the human race. &lt;a href=&quot;https://www.youtube.com/watch?v=Lq74R7wWAnQ&quot;&gt;Zerg&lt;/a&gt;, the weird creepy aliens and &lt;a href=&quot;https://www.youtube.com/watch?v=m0g0MpllFCs&quot;&gt;Protoss&lt;/a&gt;, the ancient wizards. You can also pick to play as random if you\'re up to the challenge, but I recommend sticking with one race for now.&lt;/p&gt;&lt;p&gt;The main objective of this game is pretty simple: kill the opponent\'s structures/units. A game can be won by destroying all of your opponents structures but usually players surrender before that since they know there is no way they can win the game anymore (Staying in a lost game can be seen as bad mannered.) But there\'s a lot to do before you can even start killing the opponent. The most important thing of Starcraft 2 is macro. This is what the game is all about. I\'ll tell you some more about macro later on in this post.&lt;/p&gt;&lt;p&gt;At the start of a game, you have exactly 12 workers, they are there to mine the blue crystals called \'Minerals\' for you. With these minerals you will be able to build more workers, buildings and ofcourse units. For some structures or units you will also need Vespene gas. You can extract vespene gas from the cleverly named &lt;a href=&quot;http://i.imgur.com/fHrd9su.jpg&quot;&gt;Vespene gas gysers&lt;/a&gt;. The only problem being is that you need a structure on-top of these gysers to extract the gas. You can build these structures with minerals.&lt;/p&gt;&lt;p&gt;This game has a supply cap. That means that you need to keep building supply structures or for the Zerg, units. At the beginning of the game you will need to build a supply unit/structure for you to be able to continue building workers and units. Try to keep building up supply so that you don\'t get supply blocked later on in the game. The maximum amount of supply you can have is 200.&lt;/p&gt;&lt;p&gt;Now that you know a little more about the basics, let\'s go into the deets of the 3 races we have in store for you.&lt;/p&gt;&lt;p&gt;Terran&lt;/p&gt;&lt;p&gt;Nice job picking Terran, we already have something in common. (altough I was a dirty Protoss player back in the days.)&lt;/p&gt;&lt;p&gt;Terran is the human race of this series. You will play with an army that has actually humans in it with gigantic space suits.&lt;/p&gt;&lt;p&gt;Since I have a limited supply of text I can put here, I\'d like to direct you to this a website that digs into the basics of the Terran race: &lt;a href=&quot;http://us.battle.net/sc2/en/game/race/terran/&quot;&gt;Click&lt;/a&gt; &lt;strong&gt;(Warning: Could be a little outdated.)&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Zerg&lt;/p&gt;&lt;p&gt;So you\'ve picked Zerg huh? Good choice! You\'ll probably be having a lot of fun controling this very aggressive race.&lt;/p&gt;&lt;p&gt;I recommend reading this guide about the basics of Zerg: &lt;a href=&quot;http://us.battle.net/sc2/en/blog/5740264/game-guide-zerg-basics-2-1-2012&quot;&gt;Click&lt;/a&gt; &lt;strong&gt;(Warning: Could be a little oudated.)&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Protoss&lt;/p&gt;&lt;p&gt;Nice! You picked the race which LotV is all about. You\'ll be able to control the ancient and very cool &lt;a href=&quot;https://youtu.be/8UyMAPr-G44?t=2m48s&quot;&gt;Protoss&lt;/a&gt;.&lt;/p&gt;&lt;p&gt;The basics of this race can be found here: &lt;a href=&quot;http://us.battle.net/sc2/en/game/race/protoss/&quot;&gt;Click&lt;/a&gt; &lt;strong&gt;(Warning, can be outdated)&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Micro &amp;amp; Macro.&lt;/p&gt;&lt;p&gt;Alright, we\'ve arrived at the core mechanics in this game. Micromanagement is the process of controlling your units during the game. Macromanagement is the mechanic of getting your economy up to speed and getting a good army.&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Macro&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Macro is basically the setting up, using and stabilizing your economy. From those 12 workers you get at the start you will be able to setup a great economy to make sure you get the money to build structures and army units. You want to make sure you have your game planned before the start of a game. The best way to do this for you newbies is to pick a build-order and sticking to it. With these build orders you will be able to efficiently macro. I recommend picking some from this site: &lt;a href=&quot;http://lotv.spawningtool.com/build/&quot;&gt;Click!&lt;/a&gt; and Click &lt;a href=&quot;http://imbabuilds.com/guides/how-to-read-build-orders/&quot;&gt;here&lt;/a&gt; to learn how to read these build orders.&lt;/p&gt;&lt;p&gt;Build orders are mostly used in Multiplayer, as it might not be as good during the campaign.&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Micro&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;While micro might not be as important as macro, it is still definitely something you need to know. As a new player it will be very hard to remember doing actions and doing them at a quick speed. That\'s alright, everyone on this subreddit had to learn it just like you.&lt;/p&gt;&lt;p&gt;Micromanagement is basically a term used to describe controlling your units. In this game you want to make sure you use your units abilities, position them right for engagements and use the units you have available as much as you can. Liquidpedia (our very own wikipedia) explains very well what you can do with your units in a game of Starcraft 2. You might not understand all of the terms used, but other then that micro should make a little more sense. Here\'s the guide: &lt;a href=&quot;http://wiki.teamliquid.net/starcraft2/Micro_(StarCraft)&quot;&gt;http://wiki.teamliquid.net/starcraft2/Micro_(StarCraft)&lt;/a&gt;&lt;/p&gt;&lt;p&gt;Useful links&lt;/p&gt;&lt;p&gt;There is &lt;i&gt;a lot&lt;/i&gt; more to learn about Starcraft besides what\'s mentioned above and I\'ve created a list where you can learn those things:&lt;/p&gt;&lt;p&gt;The &lt;a href=&quot;https://www.reddit.com/r/starcraft/&quot;&gt;r/starcraft&lt;/a&gt; subreddit has a nice tutorial for beginning players where you can find a lot of information; &lt;a href=&quot;https://www.reddit.com/r/starcraft/wiki/new#wiki_mechanic_tutorials&quot;&gt;Click&lt;/a&gt;&lt;/p&gt;&lt;p&gt;There are also subreddits to learn more about specific races:&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.reddit.com/r/allthingsterran/&quot;&gt;r/allthingsterran&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.reddit.com/r/allthingsprotoss/&quot;&gt;r/allthingsprotoss&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.reddit.com/r/allthingszerg/&quot;&gt;r/allthingszerg&lt;/a&gt;&lt;/p&gt;&lt;p&gt;If you have race-specific questions I recommend posting on one of the 3 subreddits listed above!&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Essential Day 9 dailies&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;We have this awesome guy in the community called Sean \'Day 9\' Plott. He is someone who shows us players how to improve our Starcraft 2 gameplay through this stream. Here are some essential Day 9 dailies that teach you newbies the essentials of Starcraft 2:&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-252-secrets-of-hotkeys-apm-and-mouse-movement/&quot;&gt;Hotkeys, APM and Mouse Movement&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.youtube.com/watch?v=QzOwja6TWeQ&quot;&gt;Dealing with Losing&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-257-newbie-tuesday-refining-mechanics/&quot;&gt;Refining Mechanics&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-261-newbie-tuesday-mechanics-2/&quot;&gt;Mechanics 2&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-360-mental-checklist-exercises/&quot;&gt;Mental Checklist&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-312-newbie-tuesday-how-to-learn-and-improve/&quot;&gt;How to Learn and Improve&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-285-newbie-tuesday-stealing-a-build/&quot;&gt;Stealing a Build&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-341-newbie-tuesday-reprioritizing-your-to-do-list/&quot;&gt;Reprioritizing your To-do List&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/day9-daily-419-newbie-tuesday-fixing-1-problem-at-a-time/&quot;&gt;Fixing 1 Problem at a Time&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/d/Day9/newbie-tuesday-optimizing-builds-week-1/&quot;&gt;Optimizing Your Builds&lt;/a&gt;&lt;/p&gt;&lt;p&gt;Also, you should totally watch This Day 9 daily #100 where he gives some more insight into the SC2 community. &lt;a href=&quot;https://www.youtube.com/watch?v=NJztfsXKcPQ&quot;&gt;Click&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Guides&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Beginners guide by &lt;a href=&quot;https://www.reddit.com/u/REInvestor/&quot;&gt;/u/REInvestor&lt;/a&gt; &lt;a href=&quot;https://www.reddit.com/r/starcraft/comments/lf73b/my_beginners_guide_to_improving_at_starcraft_2/&quot;&gt;Click&lt;/a&gt;&lt;/p&gt;&lt;p&gt;Another great beginners guide: &lt;a href=&quot;http://www.furiouspaul.com/pc/starcraft2/basics.html&quot;&gt;Click&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.youtube.com/playlist?list=PLRqcyeYtIIRrMH-bTXOXVq38rKq3BGsPS&quot;&gt;desRow\'s LotV beginner guides!&lt;/a&gt;&lt;/p&gt;&lt;p&gt;Liquipedia\'s Starcraft 2 portal: &lt;a href=&quot;http://wiki.teamliquid.net/starcraft2/StarCraft&quot;&gt;Click&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.reddit.com/u/Meoang/&quot;&gt;/u/Meoang&lt;/a&gt;\'s guides, in video form! &lt;a href=&quot;https://www.youtube.com/playlist?list=PLWJ6pGWenUxrSLhghrSdJocBKCfCgwkzo&quot;&gt;Click&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Entertainment/Comedy&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.youtube.com/watch?v=yctmP84haIk&amp;amp;list=PLujTwbNDCv6TdP13rcxubWd8rtgfVe6ln&quot;&gt;LagTV\'s when cheese fails&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.youtube.com/watch?v=8esGHkuTFl4&amp;amp;list=PLujTwbNDCv6SfdfXixVTNLp4xcdmQY20f&quot;&gt;LAGTV\'s AI Craft&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;http://day9.tv/archives/?q=%22Funday%20Monday%22&quot;&gt;Day 9\'s Funday Monday!&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.youtube.com/watch?v=VF18_ICkFnU&amp;amp;list=PLM18zsw5p4V6xtaPD0fikvgFX6Lx5dQGS&quot;&gt;/u/nice__username\'s How it looks vs How it feels&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.youtube.com/watch?v=BVFCshCRJDE&amp;amp;list=PL0QrZvg7QIgpoLdNFnEePRrU-YJfr9Be7&quot;&gt;Carbot Animation\'s \'Starcrafts\'&lt;/a&gt;&lt;/p&gt;&lt;p&gt;Esports&lt;/p&gt;&lt;p&gt;Starcraft 2 also has a big esports scene. We just got done watching the Grand finals of the Starcraft 2 World Championships Series held at Blizzcon. It was pretty exciting to watch, if I may say so myself.&lt;/p&gt;&lt;p&gt;Starcraft 2\'s esports scene is so big that I wouldn\'t be able to explain it all in this post, luckily TotalBiscuit was nice enough to make a guide about Starcraft 2 esports in video form. You can watch it here: &lt;a href=&quot;https://www.youtube.com/watch?v=JSPRgL4D1no&quot;&gt;Click&lt;/a&gt; &lt;strong&gt;Warning: Could be oudated&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Well then, that should be about it, unless I\'m missing something really important. Thank you for reading all the way, and good luck in Legacy of the Void! &amp;lt;3&lt;/p&gt;', 1, '2021-07-07 04:26:20'),
(29, 54, 2, 'Web Development future: C# instead of JavaScript', '1625606962_Csharp.png', '&lt;h2&gt;What is C#?&lt;/h2&gt;&lt;p&gt;C# is pronounced &quot;C-Sharp&quot;.&lt;/p&gt;&lt;p&gt;It is an object-oriented programming language created by Microsoft that runs on the .NET Framework.&lt;/p&gt;&lt;p&gt;C# has roots from the C family, and the language is close to other popular languages like &lt;a href=&quot;https://www.w3schools.com/cpp/default.asp&quot;&gt;C++&lt;/a&gt; and &lt;a href=&quot;https://www.w3schools.com/java/default.asp&quot;&gt;Java&lt;/a&gt;.&lt;/p&gt;&lt;p&gt;The first version was released in year 2002. The latest version, &lt;strong&gt;C# 8&lt;/strong&gt;, was released in September 2019.&lt;/p&gt;&lt;p&gt;C# is used for:&lt;/p&gt;&lt;ul&gt;&lt;li&gt;Mobile applications&lt;/li&gt;&lt;li&gt;Desktop applications&lt;/li&gt;&lt;li&gt;Web applications&lt;/li&gt;&lt;li&gt;Web services&lt;/li&gt;&lt;li&gt;Web sites&lt;/li&gt;&lt;li&gt;Games&lt;/li&gt;&lt;li&gt;VR&lt;/li&gt;&lt;li&gt;Database applications&lt;/li&gt;&lt;li&gt;And much, much more!&lt;/li&gt;&lt;/ul&gt;&lt;h2&gt;Why Use C#?&lt;/h2&gt;&lt;ul&gt;&lt;li&gt;It is one of the most popular programming language in the world&lt;/li&gt;&lt;li&gt;It is easy to learn and simple to use&lt;/li&gt;&lt;li&gt;It has a huge community support&lt;/li&gt;&lt;li&gt;C# is an object oriented language which gives a clear structure to programs and allows code to be reused, lowering development costs.&lt;/li&gt;&lt;li&gt;As C# is close to C, &lt;a href=&quot;https://www.w3schools.com/cpp/default.asp&quot;&gt;C++&lt;/a&gt; and &lt;a href=&quot;https://www.w3schools.com/java/default.asp&quot;&gt;Java&lt;/a&gt;, it makes it easy for programmers to switch to C# or vice versa&lt;/li&gt;&lt;/ul&gt;&lt;h2&gt;Get Started&lt;/h2&gt;&lt;p&gt;This tutorial will teach you the basics of C#.&lt;/p&gt;&lt;p&gt;It is not necessary to have any prior programming experience.&lt;/p&gt;', 1, '2021-07-07 04:29:22'),
(30, 54, 4, ' 3 Best Hacking Tools Of 2019 For Windows, Linux, macOS', '1625607188_best-hacking-tools.jpg', '&lt;p&gt;&lt;strong&gt;1. Metasploit | Best collection of exploit tools&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;Rather than calling &lt;strong&gt;Metasploit&lt;/strong&gt; a &lt;strong&gt;collection of exploit tools&lt;/strong&gt;, I&rsquo;ll call it an infrastructure that you can utilize to build your own custom tools. This free software is one of the most popular cybersecurity tool that allows you to locate vulnerabilities at different platforms. Metasploit is backed by more than 200,000 users and contributors that help you to get insights and uncover the weaknesses in your system.&lt;/p&gt;&lt;p&gt;This top hacking tool package of 2019 lets you simulate real-world attacks to tell you about the weak points and finds them. As a penetration tester, it pin points the vulnerabilities with Nexpose closed&ndash;loop integration using Top Remediation reports. Using the open source Metasploit framework, users can build their own tools and take the best out of this multi-purpose hacking tool.&lt;/p&gt;&lt;p&gt;Supported platforms and download:&lt;/p&gt;&lt;p&gt;Metasploit is available for all major platforms including Windows, Linux, and OS X.&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.metasploit.com/&quot;&gt;Read more here and&amp;nbsp;download&amp;nbsp;Metasploit&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;2. Acunetix WVS |&amp;nbsp;Vulnerability Scanner&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Acunetix&lt;/strong&gt; is a &lt;strong&gt;web vulnerability scanner&lt;/strong&gt; (WVS) that scans and finds out the flaws in a website that could prove fatal. This multi-threaded tool crawls a website and finds out malicious Cross-site Scripting, SQL injection, and other vulnerabilities. This fast and easy to use tool scans WordPress websites from more than 1200 vulnerabilities in WordPress.&lt;/p&gt;&lt;p&gt;Acunetix comes with a Login Sequence Recorder that allows one to access the password protected areas of websites. The new AcuSensor technology used in this tool allows you to reduce the false positive rate. Such features have made Acunetix WVS a preferred hacking tools that you need to check out in 2019.&lt;/p&gt;&lt;p&gt;Supported platforms and download:&lt;/p&gt;&lt;p&gt;Acunetix is available for Windows XP and higher.&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://www.acunetix.com/vulnerability-scanner/&quot;&gt;Read more here and download Acunetix&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;3. Nmap&amp;nbsp;| Port scanner tool&lt;/strong&gt;&lt;/p&gt;&lt;p&gt;&lt;strong&gt;Nmap&lt;/strong&gt; &ndash; also known as Network Mapper &ndash; falls in the category of a &lt;strong&gt;port scanner tool.&lt;/strong&gt; This free and open source hacking tool is the most popular port scanning tool around that allows efficient network discovery and security auditing. Used for a wide range of services, Nmap uses raw IP packets to determine the hosts available on a network, their services along with details, operating systems used by hosts, the type of firewall used, and other information.&lt;/p&gt;&lt;p&gt;Last year, Nmap won multiple security products of the year awards and was featured in multiple movies including The Matrix Reloaded, Die Hard 4, and others. &amp;nbsp;Available in the command line, Nmap executable also comes&amp;nbsp;in an advanced GUI avatar.&lt;/p&gt;&lt;p&gt;Supported platforms and download:&lt;/p&gt;&lt;p&gt;Nmap&amp;nbsp;is available for all major platforms including Windows, Linux, and OS X.&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://nmap.org/&quot;&gt;Read more here and&amp;nbsp;download Nmap&lt;/a&gt;&lt;/p&gt;', 1, '2021-07-07 04:33:08'),
(31, 54, 5, 'The best graphics cards in 2021', '1625630472_vga.jpg', '&lt;p&gt;test&lt;/p&gt;', 1, '2021-07-07 11:01:12');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `topics`
--

CREATE TABLE `topics` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Đang đổ dữ liệu cho bảng `topics`
--

INSERT INTO `topics` (`id`, `name`, `description`) VALUES
(2, 'Coding', '<p>test change</p>'),
(3, 'Gaming', ''),
(4, 'Software', ''),
(5, 'Hardware', '');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `admin` tinyint(4) NOT NULL,
  `username` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Đang đổ dữ liệu cho bảng `users`
--

INSERT INTO `users` (`id`, `admin`, `username`, `email`, `password`, `created_at`) VALUES
(54, 1, 'prohackeradmin', 'phamthachtu196@gmail.com', '$2y$10$j6Pr5NeDJWBJp/yqxu51W.ARqU37dAC9iBrdaFqIYg4UtOVOUOLfC', '2021-07-06 21:20:24'),
(61, 0, 'tudeptrai222', 'email@gmail.com', '$2y$10$moBr4hPLSEP0CjAk31uZnuVGhIcM/dlSoJvfK2s1iuS19J5oLT5Fi', '2021-07-07 04:41:55'),
(62, 0, 'nickmoitao', 'tu@gmail.com', '$2y$10$NWt8WNuOtzYBaW6jKfAO.OQx20tBZQOXVxvDQLzQWBCqhy/sgQRcy', '2021-07-07 05:16:55');

--
-- Chỉ mục cho các bảng đã đổ
--

--
-- Chỉ mục cho bảng `comments`
--
ALTER TABLE `comments`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `posts`
--
ALTER TABLE `posts`
  ADD PRIMARY KEY (`id`),
  ADD KEY `topic_id` (`topic_id`);

--
-- Chỉ mục cho bảng `topics`
--
ALTER TABLE `topics`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Chỉ mục cho bảng `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `email` (`email`);

--
-- AUTO_INCREMENT cho các bảng đã đổ
--

--
-- AUTO_INCREMENT cho bảng `comments`
--
ALTER TABLE `comments`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT cho bảng `posts`
--
ALTER TABLE `posts`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;

--
-- AUTO_INCREMENT cho bảng `topics`
--
ALTER TABLE `topics`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT cho bảng `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=63;

--
-- Các ràng buộc cho các bảng đã đổ
--

--
-- Các ràng buộc cho bảng `posts`
--
ALTER TABLE `posts`
  ADD CONSTRAINT `posts_ibfk_1` FOREIGN KEY (`topic_id`) REFERENCES `topics` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
