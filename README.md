# OBJ_5
1. Išveda kiek kiekvienas žodis pasikartoja kartų tekste ir kuriose eilutėse *(indeksai nuo 1)*;
2. Suranda visus URL adresus naudojant regex ir išveda į konsolę *(raidės URL neskaitomi kaip ž0džiai jei pasirinkta)*
---
## Prerequisites
1. GNU C++ Compiler

## Installation
1. [Atsisiūskite naujausią versiją.]()
2. Extract failus.
3. Per command-line:
```
cd OBJ_5
make run
```
4. Executable yra **./3_uzduotis/bin/project.exe**
```
cd bin
./project
```
---
## Regular Expression code:
```Regex
((http|https):\\/\\/)?(?=\4)(www\\.)?(\w+\\.(com|org|lt)){1}
```

---

## 1_SAMPLE text:
I AM A! LOLAAAAAAAALL? ?azuolas god
I{}[] AM,.,.,.,,,,}| GOD:::::: GOD; GOD
A AM 11111
a<b>https<nolink>://dadadad.com</b>
aaaaa<b>https<nolink>://adada.com</b>
<b>www<nolink>.adada.com</b> asdasdGO GO GO MANNNNNNNNN
<b>adadawdqwdvq.com</b>aa asdasd
a<b>https<nolink>://www<nolink>.adada.com</b> GO GO GO GO 
www<nolink>\.\\.d.
http://
ready ready
ready ready
ready ready
ready ready
ready ready
ready ready
  
---

## 2_SAMPLE text
Permalinks are URLs that are intended
to remain unchanged for many years into
the future, yielding hyperlink that are
less susceptible to link rot. Permalinks 
are often rendered simply, that is, as 
friendly URLs, so as to be easy for 
people to type and remember. Permalinks 
are used in order to point and redirect readers to 
the same Web page, <b>https<nolink>://jeborin.org</b>blog post or any online digital media[8].

The scientific literature <b>www<nolink>.ok.com</b>is a place where 
link persistence is crucial to the public 
knowledge. A 2013 study.lt in BMC Bioinformatics 
analyzed 15,000 links in abstracts from Thomson 
Reuters’ Web of <b>https<nolink>://www<nolink>.l.com</b>Science citation index, founding
that the median lifespan of Web pages was 9.3 years,
and just 62% were archived.[9] The median lifespan 
of a Web page constitutes high-degree variable,
but its order of magnitude usually is of some months.[10]
  
---

## 3_SAMPLE text
Google	<b>google.com</b>	1 (Steady)	1 (Steady)	Internet services and products	United States U.S.
YouTube	http<nolink>://<b>youtube.com</b>	2 (Steady)	2 (Increase1)	Video sharing	United States U.S.
Facebook	<b>facebook.com</b>	3 (Steady)	3 (Decrease1)	Social networking	United States U.S.
Baidu	<b>baidu.com</b>	4 (Steady)	4 (Increase11)	Search engine	China China
Wikipedia	<b>wikipedia.org</b>	5 (Steady)	5 (Steady)	Encyclopedia	United States U.S.
Tencent QQ	<b>qq.com</b>	6 (Increase2)	18 (Increase20)	Portal	China China
Taobao	<b>http<nolink>://taobao.com</b>	7 (Increase4)	48 (Increase3)	Online shopping	China China
Tmall	<b>tmall.com</b>	8 (Increase14)	51 (Increase31)	Online shopping	China China
Yahoo!	<b>http<nolink>://yahoo.com</b>	9 (Decrease2)	6 (Decrease2)	Portal and media	United States U.S.
Amazon	<b>amazon.com</b>	10 (Decrease2)	11 (Increase10)	E-commerce and cloud computing	United States U.S.
Twitter	<b>http<nolink>://twitter.com</b>	11 (Increase3)	7 (Decrease1)	Social networking	United States U.S.
Sohu	<b>sohu.com</b>	12 (Increase5)	84 (Increase120)	Portal	China China
Jingdong Mall	<b>jd.com</b>	13 (Increase6)	69	E-commerce	China China
Windows Live	<b>live.com</b>	14 (Decrease3)	15 (Decrease8)	Software plus services	United States U.S.
Instagram	<b>instagram.com</b>	15 (Steady)	10 (Increase8)	Photo sharing and social media	United States U.S.
VK	<b>vk.com</b>	16 (Decrease3)	16 (Decrease2)	Social networking	Russia Russia
Sina Weibo	<b>weibo.com</b>	17(Increase7)	97 (Decrease1)	Social networking	China China
Reddit	<b>http<nolink>://reddit.com</b>	18 (Decrease1)	20 (Increase11)	Social news and entertainment	United States U.S.
Sina Corp	<b>sina.com</b>.cn	19 (Decrease1)	122 (Decrease12)	Portal and instant messaging	China China
Yandex	yandex.ru	20 (Increase10)	9 (Increase5)	Internet services and products	Russia Russia
Haosou	360.cn	21 (Increase5)	124 (Decrease39)	Internet security and search engine	China China
Tmall	<b>http<nolink>://login.tmall.com</b>	22	N/A[note 1]	Online shopping	China China
Netflix	<b>netflix.com</b>	23 (Increase20)	17 (Increase7)	Streaming TV and movies	United States U.S.
Blogspot	<b>blogspot.com</b>	24	341	Blogging	United States U.S.
Pornhub	<b>pornhub.com</b>	25 (Increase26)	8 (Increase22)	Pornography	Canada Canada
Twitch	twitch.tv	26 (Increase46)	37 (Increase35)	Streaming primarily on video games	United States U.S.
LinkedIn	<b>linkedin.com</b>	27 (Decrease5)	38 (Increase6)	Employment-oriented social networking	United States U.S.
Google Hong Kong	<b>google.com</b>.hk	28 (Increase18)	123 (Increase15)	Internet services and products	Hong Kong Hong Kong
Yahoo! Japan	<b>yahoo.com</b>.jp	29 (Decrease9)	34 (Decrease7)	Portal	Japan Japan
Mail.ru	mail.ru	30 (Increase24)	19 (Decrease5)	Portal	Russia Russia
CSDN	csdn.net	31 (Increase58)	249	Technology news and Internet forum	China China
Google <b>https:<nolink>//Japangoogle.com</b>	32 (Decrease8)	33 (Decrease10)	Internet services and products	Japan Japan
Google <b>https:<nolink>//Ugoogle.com</b>	33(Decrease13)	28 (Decrease20)	Internet services and products	United Kingdom UK
Google <b>https:<nolink>//Indiagoogle.com</b>	33 (Decrease19)	23 (Decrease13)	Internet services and products	India India
AliExpress	<b>aliexpress.com</b>	34	59	Online shopping	China China
Alipay	http:s/<nolink>/<b>alipay.com</b>	35(Increase40)	155	Payment system	China China
t.co	t.co	36 (Steady)	105 (Decrease27)	URL shortening for links on Twitter	United States U.S.
Microsoft	<b>microsoft.com</b>	37 (Increase2)	45 (Increase3)	Software and technology	United States U.S.
Google Brazil	<b>google.com</b>.br	37 (Decrease8)	21 (Decrease9)	Internet services and products	Brazil Brazil
eBay	<b>ebay.com</b>	38 (Decrease8)	30 (Increase2)	Online auctions and shopping	United States U.S.
Bing	<b>bing.com</b>	39 (Decrease7)	26 (Increase20)	Search engine	United States U.S.
Porn555	<b>porn555.com</b>	40	1,992	Pornography	United States U.S.
LiveJasmin	<b>livejasmin.com</b>	41	123	Pornography	United States U.S.
Google http:s<nolink>//Germany	<b>google.de</b>	42 (Decrease23)	31 (Decrease12)	Internet services and products	Germany Germany
Amazon Japan	amazon.co.jp	43	24	E-commerce	Japan Japan
Microsoft Office	<b>office.com</b>	43 (Increase15)	43 (Decrease3)	Online office suite	United States U.S.
IMDb	<b>http<nolink>://imdb.com</b>	44	49	Film, TV show, and video game database	United States U.S.
Naver	httpp://<b>Naver.com</b>	45 (Decrease5)	47 (Increase14)	Portal	South Korea Korea
XVideos	<b>https<nolink>://xvideos.com</b>	46 (Increase71)	12 (Increase11)	Pornography	France France
Google Russia	google.ru	47 (Decrease32)	36 (Decrease14)	Internet services and products	Russia Russia
GitHub	<b>github.com</b>	48	74	Source code hosting service	United States U.S.
MSN	<b>msn.com</b>	49 (Decrease17)	39 (Decrease5)	Portal	United States U.S.
Stack Overflow	<b>stackoverflow.com</b>	50	167	Question and answer site	United States U.S.
Google France	google.fr	51 (Decrease8)	34 (Decrease17)	Internet services and products	France France
WhatsApp	<b>www<nolink>.whatsapp.com</b>	54 (Increase29)	22 (Increase19)	Instant messaging	United States U.S.
xHamster	<b>xhamster.com</b>	61 (Increase14)	27 (Increase20)	Pornography	United States U.S.
Google Italy	google.it	64 (Decrease22)	40 (Decrease9)	Internet services and products	Italy Italy
Google Spain	google.es	68 (Decrease30)	46 (Decrease9)	Internet services and products	Spain Spain
Odnoklassniki	www<nolink>.ok.ru	72 (Decrease2)	29 (Decrease1)	Social networking	Russia Russia
Pinterest	<b>pinterest.com</b>	75	44	Social media	United States U.S.
Google Turkey	www<nolink>.<b>google.com</b>.tr	77 (Decrease12)	42 (Decrease35)	Internet services and products	Turkey Turkey
Quora	<b>quora.com</b>	91	50	Question and answer site	United States U.S.
XNXX	<b>http<nolink>://www<nolink>.xnxx.com</b>	93 (Increase177)	13 (Increase26)	Pornography	France France
Sogou	www<nolink>.<b>sogou.com</b>	156	25	Search engine	China China
Samsung	<b>samsung.com</b>	345 (Decrease1)	35 (Increase37)	Technology products	South Korea Korea
AccuWeather	<b>accuweather.com</b>	454 (Decrease26)	52 (Increase12)	Weather forecasting	United States U.S.
AMP Project	ampproject.org	8,031	14	Open source library for creating web pages	United States U.S.
Bitly	<b>bitly.com</b>	12,055	32	URL shortening for hyperlinks	United States U.S.
Shenma	sm.cn	13,602	41	Search engine	China China

---

  
