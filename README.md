# Progressive-Islands-Guider

This program reads info about the progressive island from the file progressiveInput.txt and writes the guide into progressiveGuider.txt. It also makes a log in log.txt which is in most cases useless and unreadable but what you can easily read are the discount values; if you get a decimal number as a discount value you probably entered something wrong or maybe SP is just stupid. Anyway, here's what should go into progressiveInput.txt:

First line - 2 numbers: how often do you log into the game(in hours; only 1 and 8 are tested, 2 and 4 should also work and i have no idea whether any other number works) and the number of nodes.

Then, for each node you have 1 line. In that line:

The first number is the amount of gold items.

The second number is the amount of food items.

The third number is the amount of fight items.

The fourth number is the amount of breed items.

The fifth number is the amount of hatch items.

The sixth number is the amount of PvP items.

The seventh number is the total cost of the node before any items are collected.

The eighth number is the type of gold collection. Types(format: type-cost of gemming 1 gold item, cost of gemming the 2nd gold item etc.):

1-1,2,4,5,7,8,10,...

2-2,3,5,6,8,9,11,...

3-3,4,6,7,9,10,12,...

5-5,8,11,14,17,20,23,...

11-1,2,3,4,5,6,7,...

21-2,4,6,8,10,12,14,...

31-3,4,5,6,7,8,9,...

So, if the cost of buying 1 gold item is 1 gem, the cost of buying the second gold item is 2 gems and the cost of buying the third gold item is 4 gems the eighth number should be 1.

The ninth number is the type of food collection. Types:

1-1,2,3,4,5,6,...

2-2,3,4,5,6,7,...

3-3,4,5,6,7,8,...

5-5,8,11,14,17,20,...

11-1,2,4,5,7,8,...

21-2,4,6,8,10,12,...

12-1,1,2,2,3,3,4,4,...

14-1,4,7,10,13,16,...

The tenth number is the type of fight collection. Types:

3-3,7,11

5-5,11,17

8-3,5,7

10-10,20,30

12-3,4,5

13-3,9,15

The eleventh number is the type of breed collection. Types:

3-3,4,6,7,9,10,12,...

4-4,5,7,8,10,11,13,...

10-10,13,16,19,22,25,...

31-3,5,7,9,11,13,15,...

32-3,8,13,18,23,28,33,38,...

33-3,5,8,10,13,15,18,...

34-3,4,5,6,7,8,9,10,...

41-4,6,9,11,14,16,19,...

42-4,6,8,10,12,14,16,...

43-4,7,10,13,16,19,22,...

51-5,7,9,11,13,15,17,...

The 12th number is the type of hatch collection. The types are the same as for the breeding collection.

The 13th number is the type of PvP collection. For now there is only 1 type:

1-1,2,3,4,5,...

The 14th number is 0 if you can collect the first collection and 1 if you can't. Using 1 is useful when, for example, you have already made some progress and want to know what's the best way to collect until the end.

After all these lines follows a line with 3 numbers. The first number is the minimum number of hours between the first collection and the first time gems were spent. For example, if it's optimal to spend gems after 4 hours and you set this number to 8, the guider will make a strategy which spends gems after 8 hours, even if 4 is usually better. The second number is the number of days the island lasts(subtract 1 if you use boost scroll and 2 if you don't) and the third number is the number of hours the island lasts. Even if the island lasts exactly 4 days, it makes more sense to write 1 16 than 2 0 because 2 0 requires inhumanely perfect collections and may not be possible.

After that is 1 line for each node. In that line is the node's name. You can add "ignore" at the beginning of the name if you don't want to see the strategy to get to that node.

Finally, here is an example for guiding for a r5 wyrmlad if you collect every hour and didn't use gems the first 4 hours:

1

13

29 16 3 0 4 0 242 1 1 3 34 34 1 0

44 24 0 6 0 8 510 1 1 3 34 34 1 0

61 33 3 0 9 11 596 1 1 3 34 34 1 0

42 23 0 6 0 8 584 1 1 3 34 34 1 0

37 21 3 0 6 0 591 1 1 3 34 34 1 0

42 23 0 6 6 0 666 1 1 3 34 34 1 0

40 22 0 6 6 0 760 1 1 3 34 34 1 0

55 30 3 8 8 0 1144 1 1 3 34 34 1 0

49 27 0 7 7 0 1127 1 14 3 34 34 1 0

48 26 3 7 7 0 1134 1 14 3 34 34 1 0

52 28 0 7 7 0 1146 1 14 3 34 34 1 0

45 25 0 7 7 0 1138 1 14 3 34 34 1 0

53 29 0 8 8 0 1211 1 14 3 34 34 1 0

4 1 16

ignore20 cells

ignore30 cells

ignore50 cells(r0)

ignore60 cells

ignore60 cells(r1)

ignore75 cells

ignore75 cells(r2)

ignore130 cells

ignore160 cells(r3)

ignore180 cells

ignore190 cells(r4)

ignore230 cells

250 cells(r5)

And here's an example if you're going for a r0 wyrmlad, collect every 8 hours and with no restrictions on gem use:

8

13

29 16 3 0 4 0 242 1 1 3 34 34 1 0

44 24 0 6 0 8 510 1 1 3 34 34 1 0

61 33 3 0 9 11 596 1 1 3 34 34 1 0

42 23 0 6 0 8 584 1 1 3 34 34 1 0

37 21 3 0 6 0 591 1 1 3 34 34 1 0

42 23 0 6 6 0 666 1 1 3 34 34 1 0

40 22 0 6 6 0 760 1 1 3 34 34 1 0

55 30 3 8 8 0 1144 1 1 3 34 34 1 0

49 27 0 7 7 0 1127 1 14 3 34 34 1 0

48 26 3 7 7 0 1134 1 14 3 34 34 1 0

52 28 0 7 7 0 1146 1 14 3 34 34 1 0

45 25 0 7 7 0 1138 1 14 3 34 34 1 0

53 29 0 8 8 0 1211 1 14 3 34 34 1 0

0 1 16

ignore20 cells

ignore30 cells

50 cells(r0)

ignore60 cells

ignore60 cells(r1)

ignore75 cells

ignore75 cells(r2)

ignore130 cells

ignore160 cells(r3)

ignore180 cells

ignore190 cells(r4)

ignore230 cells

ignore250 cells(r5)
