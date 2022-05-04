Kvízy

Vytvořte program, který umožní vytvářet kvízy a testovat znalosti.

Implementujte následující funkcionality:

alespoň 3 různé druhy otázek (př. textová, single-choice, multi-choice)
alespoň 3 různé druhy vyhodnocení odpovědi na jeden konkrétní druh otázky (na zbylé druhy otázek může být 1 či více druhů odpovědi, př. exact-match, pattern, set)
implementujte stránky kvízu (na stránce je více otázek, kvíz má více stránek)
implementujte přechod mezi stránkami sekvenčně a v závislosti na odpovědi (př. otázka "Jaký je váš věk?" Při odpovědi 30 a víc přesměrujeme na poděkování. Jinak vyplnění další stránky s otázkami.)
uživatelské rozhraní pro tvorbu a vyplnění (a ohodnocení) kvízu
export a import kvízu (a více kvízů)
Použití polymorfismu (doporučené)

druhy otázek: textová otázka, výběr jednoho, výběr více možností, seřazení možností, ...
druhy odpovědí: textová odpověď (jedna možnost), více správných textových odpovědí, vypočtená hodnota, ...
různé formáty: vykreslení do konzole, textový (tisknutelný - bez importu, tisknutelný s výsledky - bez importu, s možností importu zpět), binární, ...
Poznámky k úloze:

Všimněte si použití polymorfismu, kde jsou ukázky v čem se liší otázka a v čem odpověď.
Zaměřte se více na pochopení úlohy z hlediska "tvůrce kvízů" (pro něj není otázka jen samotný "text", ale i forma odpovědi).
Typem vyhodnocení odpovědi je pak například pro textovou otázku (otázku s otevřenou odpovědí):
exact-match; konkrétní text (uživatel musí zadat: "červená"),
pattern; text splňující regex ("červen*", uživatel musí zadat: "červená", "červené", "červenou", "červenat", ...),
set; z množiny (uživatel musí zadat: "červená", "modrá" nebo "bílá"),
text musí obsahovat slovo (uživatel musí zadat: "červenou barvu", "vlajka má červenou", "červenou", ...),
kombinace více kritérií.

Konkrétní zadání :

Konzolová aplikace pro kvízy 
funkcionality : Spouštění existujících kvízů
.......
.......
.......
........
..........
..........
.....
..........
.....
.
.
.
.........
.............
..
........
......
.....
...
...
.....
















