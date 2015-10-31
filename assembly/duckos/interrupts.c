#define COMMON_INTERRUPT_HANDLER_EXTERN(i) extern void CommonInterruptHandler##i();

#define COMMON_INTERRUPT_HANDLER_SETUP_ENTRY(i) \
{ \
        unsigned int HandlerPtr = (unsigned int)&CommonInterruptHandler##i;\
\
        IDT_Ptr[i].HandlerPtr_Low = (unsigned short)(HandlerPtr & 0x0000FFFF);\
        IDT_Ptr[i].HandlerPtr_High = (unsigned short)((HandlerPtr >> 16) & 0x0000FFFF);\
        IDT_Ptr[i].Selector = 0x8;\
        IDT_Ptr[i].Reserved = 0x0;\
        IDT_Ptr[i].GateType = 0xE;\
        IDT_Ptr[i].StorageSegment = 0x0;\
        IDT_Ptr[i].DPL = 0x0;\
        IDT_Ptr[i].Present = 0x1;\
}

void itoa(int i, char *p);

COMMON_INTERRUPT_HANDLER_EXTERN(0)
COMMON_INTERRUPT_HANDLER_EXTERN(1)
COMMON_INTERRUPT_HANDLER_EXTERN(2)
COMMON_INTERRUPT_HANDLER_EXTERN(3)
COMMON_INTERRUPT_HANDLER_EXTERN(4)
COMMON_INTERRUPT_HANDLER_EXTERN(5)
COMMON_INTERRUPT_HANDLER_EXTERN(6)
COMMON_INTERRUPT_HANDLER_EXTERN(7)
COMMON_INTERRUPT_HANDLER_EXTERN(8)
COMMON_INTERRUPT_HANDLER_EXTERN(9)
COMMON_INTERRUPT_HANDLER_EXTERN(10)
COMMON_INTERRUPT_HANDLER_EXTERN(11)
COMMON_INTERRUPT_HANDLER_EXTERN(12)
COMMON_INTERRUPT_HANDLER_EXTERN(13)
COMMON_INTERRUPT_HANDLER_EXTERN(14)
COMMON_INTERRUPT_HANDLER_EXTERN(15)
COMMON_INTERRUPT_HANDLER_EXTERN(16)
COMMON_INTERRUPT_HANDLER_EXTERN(17)
COMMON_INTERRUPT_HANDLER_EXTERN(18)
COMMON_INTERRUPT_HANDLER_EXTERN(19)
COMMON_INTERRUPT_HANDLER_EXTERN(20)
COMMON_INTERRUPT_HANDLER_EXTERN(21)
COMMON_INTERRUPT_HANDLER_EXTERN(22)
COMMON_INTERRUPT_HANDLER_EXTERN(23)
COMMON_INTERRUPT_HANDLER_EXTERN(24)
COMMON_INTERRUPT_HANDLER_EXTERN(25)
COMMON_INTERRUPT_HANDLER_EXTERN(26)
COMMON_INTERRUPT_HANDLER_EXTERN(27)
COMMON_INTERRUPT_HANDLER_EXTERN(28)
COMMON_INTERRUPT_HANDLER_EXTERN(29)
COMMON_INTERRUPT_HANDLER_EXTERN(30)
COMMON_INTERRUPT_HANDLER_EXTERN(31)
COMMON_INTERRUPT_HANDLER_EXTERN(32)
COMMON_INTERRUPT_HANDLER_EXTERN(33)
COMMON_INTERRUPT_HANDLER_EXTERN(34)
COMMON_INTERRUPT_HANDLER_EXTERN(35)
COMMON_INTERRUPT_HANDLER_EXTERN(36)
COMMON_INTERRUPT_HANDLER_EXTERN(37)
COMMON_INTERRUPT_HANDLER_EXTERN(38)
COMMON_INTERRUPT_HANDLER_EXTERN(39)
COMMON_INTERRUPT_HANDLER_EXTERN(40)
COMMON_INTERRUPT_HANDLER_EXTERN(41)
COMMON_INTERRUPT_HANDLER_EXTERN(42)
COMMON_INTERRUPT_HANDLER_EXTERN(43)
COMMON_INTERRUPT_HANDLER_EXTERN(44)
COMMON_INTERRUPT_HANDLER_EXTERN(45)
COMMON_INTERRUPT_HANDLER_EXTERN(46)
COMMON_INTERRUPT_HANDLER_EXTERN(47)
COMMON_INTERRUPT_HANDLER_EXTERN(48)
COMMON_INTERRUPT_HANDLER_EXTERN(49)
COMMON_INTERRUPT_HANDLER_EXTERN(50)
COMMON_INTERRUPT_HANDLER_EXTERN(51)
COMMON_INTERRUPT_HANDLER_EXTERN(52)
COMMON_INTERRUPT_HANDLER_EXTERN(53)
COMMON_INTERRUPT_HANDLER_EXTERN(54)
COMMON_INTERRUPT_HANDLER_EXTERN(55)
COMMON_INTERRUPT_HANDLER_EXTERN(56)
COMMON_INTERRUPT_HANDLER_EXTERN(57)
COMMON_INTERRUPT_HANDLER_EXTERN(58)
COMMON_INTERRUPT_HANDLER_EXTERN(59)
COMMON_INTERRUPT_HANDLER_EXTERN(60)
COMMON_INTERRUPT_HANDLER_EXTERN(61)
COMMON_INTERRUPT_HANDLER_EXTERN(62)
COMMON_INTERRUPT_HANDLER_EXTERN(63)
COMMON_INTERRUPT_HANDLER_EXTERN(64)
COMMON_INTERRUPT_HANDLER_EXTERN(65)
COMMON_INTERRUPT_HANDLER_EXTERN(66)
COMMON_INTERRUPT_HANDLER_EXTERN(67)
COMMON_INTERRUPT_HANDLER_EXTERN(68)
COMMON_INTERRUPT_HANDLER_EXTERN(69)
COMMON_INTERRUPT_HANDLER_EXTERN(70)
COMMON_INTERRUPT_HANDLER_EXTERN(71)
COMMON_INTERRUPT_HANDLER_EXTERN(72)
COMMON_INTERRUPT_HANDLER_EXTERN(73)
COMMON_INTERRUPT_HANDLER_EXTERN(74)
COMMON_INTERRUPT_HANDLER_EXTERN(75)
COMMON_INTERRUPT_HANDLER_EXTERN(76)
COMMON_INTERRUPT_HANDLER_EXTERN(77)
COMMON_INTERRUPT_HANDLER_EXTERN(78)
COMMON_INTERRUPT_HANDLER_EXTERN(79)
COMMON_INTERRUPT_HANDLER_EXTERN(80)
COMMON_INTERRUPT_HANDLER_EXTERN(81)
COMMON_INTERRUPT_HANDLER_EXTERN(82)
COMMON_INTERRUPT_HANDLER_EXTERN(83)
COMMON_INTERRUPT_HANDLER_EXTERN(84)
COMMON_INTERRUPT_HANDLER_EXTERN(85)
COMMON_INTERRUPT_HANDLER_EXTERN(86)
COMMON_INTERRUPT_HANDLER_EXTERN(87)
COMMON_INTERRUPT_HANDLER_EXTERN(88)
COMMON_INTERRUPT_HANDLER_EXTERN(89)
COMMON_INTERRUPT_HANDLER_EXTERN(90)
COMMON_INTERRUPT_HANDLER_EXTERN(91)
COMMON_INTERRUPT_HANDLER_EXTERN(92)
COMMON_INTERRUPT_HANDLER_EXTERN(93)
COMMON_INTERRUPT_HANDLER_EXTERN(94)
COMMON_INTERRUPT_HANDLER_EXTERN(95)
COMMON_INTERRUPT_HANDLER_EXTERN(96)
COMMON_INTERRUPT_HANDLER_EXTERN(97)
COMMON_INTERRUPT_HANDLER_EXTERN(98)
COMMON_INTERRUPT_HANDLER_EXTERN(99)
COMMON_INTERRUPT_HANDLER_EXTERN(100)
COMMON_INTERRUPT_HANDLER_EXTERN(101)
COMMON_INTERRUPT_HANDLER_EXTERN(102)
COMMON_INTERRUPT_HANDLER_EXTERN(103)
COMMON_INTERRUPT_HANDLER_EXTERN(104)
COMMON_INTERRUPT_HANDLER_EXTERN(105)
COMMON_INTERRUPT_HANDLER_EXTERN(106)
COMMON_INTERRUPT_HANDLER_EXTERN(107)
COMMON_INTERRUPT_HANDLER_EXTERN(108)
COMMON_INTERRUPT_HANDLER_EXTERN(109)
COMMON_INTERRUPT_HANDLER_EXTERN(110)
COMMON_INTERRUPT_HANDLER_EXTERN(111)
COMMON_INTERRUPT_HANDLER_EXTERN(112)
COMMON_INTERRUPT_HANDLER_EXTERN(113)
COMMON_INTERRUPT_HANDLER_EXTERN(114)
COMMON_INTERRUPT_HANDLER_EXTERN(115)
COMMON_INTERRUPT_HANDLER_EXTERN(116)
COMMON_INTERRUPT_HANDLER_EXTERN(117)
COMMON_INTERRUPT_HANDLER_EXTERN(118)
COMMON_INTERRUPT_HANDLER_EXTERN(119)
COMMON_INTERRUPT_HANDLER_EXTERN(120)
COMMON_INTERRUPT_HANDLER_EXTERN(121)
COMMON_INTERRUPT_HANDLER_EXTERN(122)
COMMON_INTERRUPT_HANDLER_EXTERN(123)
COMMON_INTERRUPT_HANDLER_EXTERN(124)
COMMON_INTERRUPT_HANDLER_EXTERN(125)
COMMON_INTERRUPT_HANDLER_EXTERN(126)
COMMON_INTERRUPT_HANDLER_EXTERN(127)
COMMON_INTERRUPT_HANDLER_EXTERN(128)
COMMON_INTERRUPT_HANDLER_EXTERN(129)
COMMON_INTERRUPT_HANDLER_EXTERN(130)
COMMON_INTERRUPT_HANDLER_EXTERN(131)
COMMON_INTERRUPT_HANDLER_EXTERN(132)
COMMON_INTERRUPT_HANDLER_EXTERN(133)
COMMON_INTERRUPT_HANDLER_EXTERN(134)
COMMON_INTERRUPT_HANDLER_EXTERN(135)
COMMON_INTERRUPT_HANDLER_EXTERN(136)
COMMON_INTERRUPT_HANDLER_EXTERN(137)
COMMON_INTERRUPT_HANDLER_EXTERN(138)
COMMON_INTERRUPT_HANDLER_EXTERN(139)
COMMON_INTERRUPT_HANDLER_EXTERN(140)
COMMON_INTERRUPT_HANDLER_EXTERN(141)
COMMON_INTERRUPT_HANDLER_EXTERN(142)
COMMON_INTERRUPT_HANDLER_EXTERN(143)
COMMON_INTERRUPT_HANDLER_EXTERN(144)
COMMON_INTERRUPT_HANDLER_EXTERN(145)
COMMON_INTERRUPT_HANDLER_EXTERN(146)
COMMON_INTERRUPT_HANDLER_EXTERN(147)
COMMON_INTERRUPT_HANDLER_EXTERN(148)
COMMON_INTERRUPT_HANDLER_EXTERN(149)
COMMON_INTERRUPT_HANDLER_EXTERN(150)
COMMON_INTERRUPT_HANDLER_EXTERN(151)
COMMON_INTERRUPT_HANDLER_EXTERN(152)
COMMON_INTERRUPT_HANDLER_EXTERN(153)
COMMON_INTERRUPT_HANDLER_EXTERN(154)
COMMON_INTERRUPT_HANDLER_EXTERN(155)
COMMON_INTERRUPT_HANDLER_EXTERN(156)
COMMON_INTERRUPT_HANDLER_EXTERN(157)
COMMON_INTERRUPT_HANDLER_EXTERN(158)
COMMON_INTERRUPT_HANDLER_EXTERN(159)
COMMON_INTERRUPT_HANDLER_EXTERN(160)
COMMON_INTERRUPT_HANDLER_EXTERN(161)
COMMON_INTERRUPT_HANDLER_EXTERN(162)
COMMON_INTERRUPT_HANDLER_EXTERN(163)
COMMON_INTERRUPT_HANDLER_EXTERN(164)
COMMON_INTERRUPT_HANDLER_EXTERN(165)
COMMON_INTERRUPT_HANDLER_EXTERN(166)
COMMON_INTERRUPT_HANDLER_EXTERN(167)
COMMON_INTERRUPT_HANDLER_EXTERN(168)
COMMON_INTERRUPT_HANDLER_EXTERN(169)
COMMON_INTERRUPT_HANDLER_EXTERN(170)
COMMON_INTERRUPT_HANDLER_EXTERN(171)
COMMON_INTERRUPT_HANDLER_EXTERN(172)
COMMON_INTERRUPT_HANDLER_EXTERN(173)
COMMON_INTERRUPT_HANDLER_EXTERN(174)
COMMON_INTERRUPT_HANDLER_EXTERN(175)
COMMON_INTERRUPT_HANDLER_EXTERN(176)
COMMON_INTERRUPT_HANDLER_EXTERN(177)
COMMON_INTERRUPT_HANDLER_EXTERN(178)
COMMON_INTERRUPT_HANDLER_EXTERN(179)
COMMON_INTERRUPT_HANDLER_EXTERN(180)
COMMON_INTERRUPT_HANDLER_EXTERN(181)
COMMON_INTERRUPT_HANDLER_EXTERN(182)
COMMON_INTERRUPT_HANDLER_EXTERN(183)
COMMON_INTERRUPT_HANDLER_EXTERN(184)
COMMON_INTERRUPT_HANDLER_EXTERN(185)
COMMON_INTERRUPT_HANDLER_EXTERN(186)
COMMON_INTERRUPT_HANDLER_EXTERN(187)
COMMON_INTERRUPT_HANDLER_EXTERN(188)
COMMON_INTERRUPT_HANDLER_EXTERN(189)
COMMON_INTERRUPT_HANDLER_EXTERN(190)
COMMON_INTERRUPT_HANDLER_EXTERN(191)
COMMON_INTERRUPT_HANDLER_EXTERN(192)
COMMON_INTERRUPT_HANDLER_EXTERN(193)
COMMON_INTERRUPT_HANDLER_EXTERN(194)
COMMON_INTERRUPT_HANDLER_EXTERN(195)
COMMON_INTERRUPT_HANDLER_EXTERN(196)
COMMON_INTERRUPT_HANDLER_EXTERN(197)
COMMON_INTERRUPT_HANDLER_EXTERN(198)
COMMON_INTERRUPT_HANDLER_EXTERN(199)
COMMON_INTERRUPT_HANDLER_EXTERN(200)
COMMON_INTERRUPT_HANDLER_EXTERN(201)
COMMON_INTERRUPT_HANDLER_EXTERN(202)
COMMON_INTERRUPT_HANDLER_EXTERN(203)
COMMON_INTERRUPT_HANDLER_EXTERN(204)
COMMON_INTERRUPT_HANDLER_EXTERN(205)
COMMON_INTERRUPT_HANDLER_EXTERN(206)
COMMON_INTERRUPT_HANDLER_EXTERN(207)
COMMON_INTERRUPT_HANDLER_EXTERN(208)
COMMON_INTERRUPT_HANDLER_EXTERN(209)
COMMON_INTERRUPT_HANDLER_EXTERN(210)
COMMON_INTERRUPT_HANDLER_EXTERN(211)
COMMON_INTERRUPT_HANDLER_EXTERN(212)
COMMON_INTERRUPT_HANDLER_EXTERN(213)
COMMON_INTERRUPT_HANDLER_EXTERN(214)
COMMON_INTERRUPT_HANDLER_EXTERN(215)
COMMON_INTERRUPT_HANDLER_EXTERN(216)
COMMON_INTERRUPT_HANDLER_EXTERN(217)
COMMON_INTERRUPT_HANDLER_EXTERN(218)
COMMON_INTERRUPT_HANDLER_EXTERN(219)
COMMON_INTERRUPT_HANDLER_EXTERN(220)
COMMON_INTERRUPT_HANDLER_EXTERN(221)
COMMON_INTERRUPT_HANDLER_EXTERN(222)
COMMON_INTERRUPT_HANDLER_EXTERN(223)
COMMON_INTERRUPT_HANDLER_EXTERN(224)
COMMON_INTERRUPT_HANDLER_EXTERN(225)
COMMON_INTERRUPT_HANDLER_EXTERN(226)
COMMON_INTERRUPT_HANDLER_EXTERN(227)
COMMON_INTERRUPT_HANDLER_EXTERN(228)
COMMON_INTERRUPT_HANDLER_EXTERN(229)
COMMON_INTERRUPT_HANDLER_EXTERN(230)
COMMON_INTERRUPT_HANDLER_EXTERN(231)
COMMON_INTERRUPT_HANDLER_EXTERN(232)
COMMON_INTERRUPT_HANDLER_EXTERN(233)
COMMON_INTERRUPT_HANDLER_EXTERN(234)
COMMON_INTERRUPT_HANDLER_EXTERN(235)
COMMON_INTERRUPT_HANDLER_EXTERN(236)
COMMON_INTERRUPT_HANDLER_EXTERN(237)
COMMON_INTERRUPT_HANDLER_EXTERN(238)
COMMON_INTERRUPT_HANDLER_EXTERN(239)
COMMON_INTERRUPT_HANDLER_EXTERN(240)
COMMON_INTERRUPT_HANDLER_EXTERN(241)
COMMON_INTERRUPT_HANDLER_EXTERN(242)
COMMON_INTERRUPT_HANDLER_EXTERN(243)
COMMON_INTERRUPT_HANDLER_EXTERN(244)
COMMON_INTERRUPT_HANDLER_EXTERN(245)
COMMON_INTERRUPT_HANDLER_EXTERN(246)
COMMON_INTERRUPT_HANDLER_EXTERN(247)
COMMON_INTERRUPT_HANDLER_EXTERN(248)
COMMON_INTERRUPT_HANDLER_EXTERN(249)
COMMON_INTERRUPT_HANDLER_EXTERN(250)
COMMON_INTERRUPT_HANDLER_EXTERN(251)
COMMON_INTERRUPT_HANDLER_EXTERN(252)
COMMON_INTERRUPT_HANDLER_EXTERN(253)
COMMON_INTERRUPT_HANDLER_EXTERN(254)
COMMON_INTERRUPT_HANDLER_EXTERN(255)

void IssueInterrupt(unsigned char num)
{
        switch(num)
        {
                case 0: __asm__ ("int 0\n" ); break;
                case 1: __asm__ ("int 1\n" ); break;
                case 2: __asm__ ("int 2\n" ); break;
                case 3: __asm__ ("int 3\n" ); break;
                case 4: __asm__ ("int 4\n" ); break;
                case 5: __asm__ ("int 5\n" ); break;
                case 6: __asm__ ("int 6\n" ); break;
                case 7: __asm__ ("int 7\n" ); break;
                case 8: __asm__ ("int 8\n" ); break;
                case 9: __asm__ ("int 9\n" ); break;
                case 10: __asm__ ("int 10\n" ); break;
                case 11: __asm__ ("int 11\n" ); break;
                case 12: __asm__ ("int 12\n" ); break;
                case 13: __asm__ ("int 13\n" ); break;
                case 14: __asm__ ("int 14\n" ); break;
                case 15: __asm__ ("int 15\n" ); break;
                case 16: __asm__ ("int 16\n" ); break;
                case 17: __asm__ ("int 17\n" ); break;
                case 18: __asm__ ("int 18\n" ); break;
                case 19: __asm__ ("int 19\n" ); break;
                case 20: __asm__ ("int 20\n" ); break;
                case 21: __asm__ ("int 21\n" ); break;
                case 22: __asm__ ("int 22\n" ); break;
                case 23: __asm__ ("int 23\n" ); break;
                case 24: __asm__ ("int 24\n" ); break;
                case 25: __asm__ ("int 25\n" ); break;
                case 26: __asm__ ("int 26\n" ); break;
                case 27: __asm__ ("int 27\n" ); break;
                case 28: __asm__ ("int 28\n" ); break;
                case 29: __asm__ ("int 29\n" ); break;
                case 30: __asm__ ("int 30\n" ); break;
                case 31: __asm__ ("int 31\n" ); break;
		case 32: __asm__ ("int 32\n" ); break;
                case 33: __asm__ ("int 33\n" ); break;
                case 34: __asm__ ("int 34\n" ); break;
                case 35: __asm__ ("int 35\n" ); break;
                case 36: __asm__ ("int 36\n" ); break;
                case 37: __asm__ ("int 37\n" ); break;
                case 38: __asm__ ("int 38\n" ); break;
                case 39: __asm__ ("int 39\n" ); break;
                case 40: __asm__ ("int 40\n" ); break;
                case 41: __asm__ ("int 41\n" ); break;
                case 42: __asm__ ("int 42\n" ); break;
                case 43: __asm__ ("int 43\n" ); break;
                case 44: __asm__ ("int 44\n" ); break;
                case 45: __asm__ ("int 45\n" ); break;
                case 46: __asm__ ("int 46\n" ); break;
                case 47: __asm__ ("int 47\n" ); break;
                case 48: __asm__ ("int 48\n" ); break;
                case 49: __asm__ ("int 49\n" ); break;
                case 50: __asm__ ("int 50\n" ); break;
                case 51: __asm__ ("int 51\n" ); break;
                case 52: __asm__ ("int 52\n" ); break;
                case 53: __asm__ ("int 53\n" ); break;
                case 54: __asm__ ("int 54\n" ); break;
                case 55: __asm__ ("int 55\n" ); break;
                case 56: __asm__ ("int 56\n" ); break;
                case 57: __asm__ ("int 57\n" ); break;
                case 58: __asm__ ("int 58\n" ); break;
                case 59: __asm__ ("int 59\n" ); break;
                case 60: __asm__ ("int 60\n" ); break;
                case 61: __asm__ ("int 61\n" ); break;
                case 62: __asm__ ("int 62\n" ); break;
                case 63: __asm__ ("int 63\n" ); break;
                case 64: __asm__ ("int 64\n" ); break;
                case 65: __asm__ ("int 65\n" ); break;
                case 66: __asm__ ("int 66\n" ); break;
                case 67: __asm__ ("int 67\n" ); break;
                case 68: __asm__ ("int 68\n" ); break;
                case 69: __asm__ ("int 69\n" ); break;
                case 70: __asm__ ("int 70\n" ); break;
                case 71: __asm__ ("int 71\n" ); break;
                case 72: __asm__ ("int 72\n" ); break;
                case 73: __asm__ ("int 73\n" ); break;
                case 74: __asm__ ("int 74\n" ); break;
		case 75: __asm__ ("int 75\n" ); break;
                case 76: __asm__ ("int 76\n" ); break;
                case 77: __asm__ ("int 77\n" ); break;
                case 78: __asm__ ("int 78\n" ); break;
                case 79: __asm__ ("int 79\n" ); break;
                case 80: __asm__ ("int 80\n" ); break;
                case 81: __asm__ ("int 81\n" ); break;
                case 82: __asm__ ("int 82\n" ); break;
                case 83: __asm__ ("int 83\n" ); break;
                case 84: __asm__ ("int 84\n" ); break;
                case 85: __asm__ ("int 85\n" ); break;
                case 86: __asm__ ("int 86\n" ); break;
                case 87: __asm__ ("int 87\n" ); break;
                case 88: __asm__ ("int 88\n" ); break;
                case 89: __asm__ ("int 89\n" ); break;
                case 90: __asm__ ("int 90\n" ); break;
                case 91: __asm__ ("int 91\n" ); break;
                case 92: __asm__ ("int 92\n" ); break;
                case 93: __asm__ ("int 93\n" ); break;
                case 94: __asm__ ("int 94\n" ); break;
                case 95: __asm__ ("int 95\n" ); break;
                case 96: __asm__ ("int 96\n" ); break;
                case 97: __asm__ ("int 97\n" ); break;
                case 98: __asm__ ("int 98\n" ); break;
                case 99: __asm__ ("int 99\n" ); break;
                case 100: __asm__ ("int 100\n" ); break;
                case 101: __asm__ ("int 101\n" ); break;
                case 102: __asm__ ("int 102\n" ); break;
                case 103: __asm__ ("int 103\n" ); break;
                case 104: __asm__ ("int 104\n" ); break;
                case 105: __asm__ ("int 105\n" ); break;
                case 106: __asm__ ("int 106\n" ); break;
                case 107: __asm__ ("int 107\n" ); break;
                case 108: __asm__ ("int 108\n" ); break;
                case 109: __asm__ ("int 109\n" ); break;
                case 110: __asm__ ("int 110\n" ); break;
                case 111: __asm__ ("int 111\n" ); break;
                case 112: __asm__ ("int 112\n" ); break;
                case 113: __asm__ ("int 113\n" ); break;
                case 114: __asm__ ("int 114\n" ); break;
                case 115: __asm__ ("int 115\n" ); break;
                case 116: __asm__ ("int 116\n" ); break;
                case 117: __asm__ ("int 117\n" ); break;
                case 118: __asm__ ("int 118\n" ); break;
                case 119: __asm__ ("int 119\n" ); break;
                case 120: __asm__ ("int 120\n" ); break;
                case 121: __asm__ ("int 121\n" ); break;
                case 122: __asm__ ("int 122\n" ); break;
                case 123: __asm__ ("int 123\n" ); break;
                case 124: __asm__ ("int 124\n" ); break;
                case 125: __asm__ ("int 125\n" ); break;
                case 126: __asm__ ("int 126\n" ); break;
                case 127: __asm__ ("int 127\n" ); break;
                case 128: __asm__ ("int 128\n" ); break;
                case 129: __asm__ ("int 129\n" ); break;
                case 130: __asm__ ("int 130\n" ); break;
                case 131: __asm__ ("int 131\n" ); break;
                case 132: __asm__ ("int 132\n" ); break;
                case 133: __asm__ ("int 133\n" ); break;
                case 134: __asm__ ("int 134\n" ); break;
                case 135: __asm__ ("int 135\n" ); break;
                case 136: __asm__ ("int 136\n" ); break;
                case 137: __asm__ ("int 137\n" ); break;
                case 138: __asm__ ("int 138\n" ); break;
                case 139: __asm__ ("int 139\n" ); break;
                case 140: __asm__ ("int 140\n" ); break;
                case 141: __asm__ ("int 141\n" ); break;
                case 142: __asm__ ("int 142\n" ); break;
                case 143: __asm__ ("int 143\n" ); break;
                case 144: __asm__ ("int 144\n" ); break;
                case 145: __asm__ ("int 145\n" ); break;
                case 146: __asm__ ("int 146\n" ); break;
                case 147: __asm__ ("int 147\n" ); break;
                case 148: __asm__ ("int 148\n" ); break;
                case 149: __asm__ ("int 149\n" ); break;
                case 150: __asm__ ("int 150\n" ); break;
                case 151: __asm__ ("int 151\n" ); break;
                case 152: __asm__ ("int 152\n" ); break;
                case 153: __asm__ ("int 153\n" ); break;
                case 154: __asm__ ("int 154\n" ); break;
                case 155: __asm__ ("int 155\n" ); break;
                case 156: __asm__ ("int 156\n" ); break;
                case 157: __asm__ ("int 157\n" ); break;
                case 158: __asm__ ("int 158\n" ); break;
                case 159: __asm__ ("int 159\n" ); break;
                case 160: __asm__ ("int 160\n" ); break;
                case 161: __asm__ ("int 161\n" ); break;
                case 162: __asm__ ("int 162\n" ); break;
                case 163: __asm__ ("int 163\n" ); break;
                case 164: __asm__ ("int 164\n" ); break;
                case 165: __asm__ ("int 165\n" ); break;
                case 166: __asm__ ("int 166\n" ); break;
                case 167: __asm__ ("int 167\n" ); break;
                case 168: __asm__ ("int 168\n" ); break;
                case 169: __asm__ ("int 169\n" ); break;
                case 170: __asm__ ("int 170\n" ); break;
                case 171: __asm__ ("int 171\n" ); break;
                case 172: __asm__ ("int 172\n" ); break;
                case 173: __asm__ ("int 173\n" ); break;
                case 174: __asm__ ("int 174\n" ); break;
                case 175: __asm__ ("int 175\n" ); break;
                case 176: __asm__ ("int 176\n" ); break;
                case 177: __asm__ ("int 177\n" ); break;
                case 178: __asm__ ("int 178\n" ); break;
                case 179: __asm__ ("int 179\n" ); break;
                case 180: __asm__ ("int 180\n" ); break;
                case 181: __asm__ ("int 181\n" ); break;
                case 182: __asm__ ("int 182\n" ); break;
                case 183: __asm__ ("int 183\n" ); break;
                case 184: __asm__ ("int 184\n" ); break;
                case 185: __asm__ ("int 185\n" ); break;
                case 186: __asm__ ("int 186\n" ); break;
                case 187: __asm__ ("int 187\n" ); break;
                case 188: __asm__ ("int 188\n" ); break;
                case 189: __asm__ ("int 189\n" ); break;
                case 190: __asm__ ("int 190\n" ); break;
                case 191: __asm__ ("int 191\n" ); break;
                case 192: __asm__ ("int 192\n" ); break;
                case 193: __asm__ ("int 193\n" ); break;
                case 194: __asm__ ("int 194\n" ); break;
                case 195: __asm__ ("int 195\n" ); break;
                case 196: __asm__ ("int 196\n" ); break;
                case 197: __asm__ ("int 197\n" ); break;
                case 198: __asm__ ("int 198\n" ); break;
                case 199: __asm__ ("int 199\n" ); break;
                case 200: __asm__ ("int 200\n" ); break;
                case 201: __asm__ ("int 201\n" ); break;
                case 202: __asm__ ("int 202\n" ); break;
                case 203: __asm__ ("int 203\n" ); break;
                case 204: __asm__ ("int 204\n" ); break;
                case 205: __asm__ ("int 205\n" ); break;
                case 206: __asm__ ("int 206\n" ); break;
                case 207: __asm__ ("int 207\n" ); break;
                case 208: __asm__ ("int 208\n" ); break;
                case 209: __asm__ ("int 209\n" ); break;
                case 210: __asm__ ("int 210\n" ); break;
                case 211: __asm__ ("int 211\n" ); break;
                case 212: __asm__ ("int 212\n" ); break;
                case 213: __asm__ ("int 213\n" ); break;
                case 214: __asm__ ("int 214\n" ); break;
                case 215: __asm__ ("int 215\n" ); break;
                case 216: __asm__ ("int 216\n" ); break;
                case 217: __asm__ ("int 217\n" ); break;
                case 218: __asm__ ("int 218\n" ); break;
                case 219: __asm__ ("int 219\n" ); break;
                case 220: __asm__ ("int 220\n" ); break;
                case 221: __asm__ ("int 221\n" ); break;
                case 222: __asm__ ("int 222\n" ); break;
                case 223: __asm__ ("int 223\n" ); break;
                case 224: __asm__ ("int 224\n" ); break;
                case 225: __asm__ ("int 225\n" ); break;
                case 226: __asm__ ("int 226\n" ); break;
                case 227: __asm__ ("int 227\n" ); break;
                case 228: __asm__ ("int 228\n" ); break;
                case 229: __asm__ ("int 229\n" ); break;
                case 230: __asm__ ("int 230\n" ); break;
                case 231: __asm__ ("int 231\n" ); break;
                case 232: __asm__ ("int 232\n" ); break;
                case 233: __asm__ ("int 233\n" ); break;
                case 234: __asm__ ("int 234\n" ); break;
                case 235: __asm__ ("int 235\n" ); break;
                case 236: __asm__ ("int 236\n" ); break;
                case 237: __asm__ ("int 237\n" ); break;
                case 238: __asm__ ("int 238\n" ); break;
                case 239: __asm__ ("int 239\n" ); break;
                case 240: __asm__ ("int 240\n" ); break;
                case 241: __asm__ ("int 241\n" ); break;
                case 242: __asm__ ("int 242\n" ); break;
                case 243: __asm__ ("int 243\n" ); break;
                case 244: __asm__ ("int 244\n" ); break;
                case 245: __asm__ ("int 245\n" ); break;
                case 246: __asm__ ("int 246\n" ); break;
                case 247: __asm__ ("int 247\n" ); break;
                case 248: __asm__ ("int 248\n" ); break;
                case 249: __asm__ ("int 249\n" ); break;
                case 250: __asm__ ("int 250\n" ); break;
                case 251: __asm__ ("int 251\n" ); break;
                case 252: __asm__ ("int 252\n" ); break;
                case 253: __asm__ ("int 253\n" ); break;
                case 254: __asm__ ("int 254\n" ); break;
                case 255: __asm__ ("int 255\n" ); break;
        }
}

void CommonInterruptHandler(int handlerNum) {
  static char shiftPressed = 0;
  static char ctrlPressed = 0;
  static char altPressed = 0;

  unsigned char scanCode;

        DisplayColourArea(0xF, 0xF, handlerNum, 1);
        Delay();
        DisplayColourArea(0x0, 0xF, handlerNum, 1);

        if(handlerNum == 33)
        {
    /* Note: If you add or remove local variables to/from this method or change
             any function calls (including adding/removing arguments) you must 
             update the EBP-9 value below.
             
             Uncomment the line of code following this paragraph. Recompile and
             then inspect the main.s assembly code file outputted by the compiler. 
             Search for "CommonInterruptHandler:" then scroll down to 
             "inb AL, 0x60" and look at the line of code above which sets the 
             local variable. Update the asm following this comment appropriately.
             
      scanCode = -1;
      
    */

                __asm__
                (
                        "inb AL, 0x60\n"
      "mov byte ptr [EBP-9], al\n"
                );

    unsigned int shiftedScanCode;
    unsigned char processChar = 1;
    unsigned char released = (scanCode & 0x80);
    if(released)
    {
      scanCode ^= 0x80;
    }

    shiftedScanCode = scanCode;
    switch (shiftedScanCode)
    {
      //Left and right shift keys
      case 0x36:
      case 0x2A:
        {
          shiftPressed = !released;
          processChar = 0;
          break;
        }
      //Ctrl key
      case 0x1D:
        {
          ctrlPressed = !released;
          processChar = 0;
          break;
        }
      //Alt key
      case 0x38:
        {
          altPressed = !released;
          processChar = 0;
          break;
        }
      //All other keys
      default:
        {
          //If the key was just pressed, enqueue it
          if (!released)
          {
            //If shift pressed, adjust the scancode appropriately.
            if (shiftPressed)
            {
              shiftedScanCode = shiftedScanCode << 16;
            }
          }
          else
          {
            processChar = 0;
          }
        }
        break;
    }

    if(processChar)
    {
      char character[2];
      switch (shiftedScanCode)
      {
        case 0x10: character[0] = 'q'; break;
        case 0x100000: character[0] = 'Q'; break;
        case 0x11: character[0] = 'w'; break;
        case 0x110000: character[0] = 'W'; break;
        case 0x12: character[0] = 'e'; break;
        case 0x120000: character[0] = 'E'; break;
        case 0x13: character[0] = 'r'; break;
        case 0x130000: character[0] = 'R'; break;
        case 0x14: character[0] = 't'; break;
        case 0x140000: character[0] = 'T'; break;
        case 0x15: character[0] = 'y'; break;
        case 0x150000: character[0] = 'Y'; break;
        case 0x16: character[0] = 'u'; break;
        case 0x160000: character[0] = 'U'; break;
        case 0x17: character[0] = 'i'; break;
        case 0x170000: character[0] = 'I'; break;
        case 0x18: character[0] = 'o'; break;
        case 0x180000: character[0] = 'O'; break;
        case 0x19: character[0] = 'p'; break;
        case 0x190000: character[0] = 'P'; break;

        case 0x1E: character[0] = 'a'; break;
        case 0x1E0000: character[0] = 'A'; break;
        case 0x1F: character[0] = 's'; break;
        case 0x1F0000: character[0] = 'S'; break;
        case 0x20: character[0] = 'd'; break;
        case 0x200000: character[0] = 'D'; break;
        case 0x21: character[0] = 'f'; break;
        case 0x210000: character[0] = 'F'; break;
        case 0x22: character[0] = 'g'; break;
        case 0x220000: character[0] = 'G'; break;
        case 0x23: character[0] = 'h'; break;
        case 0x230000: character[0] = 'H'; break;
        case 0x24: character[0] = 'j'; break;
        case 0x240000: character[0] = 'J'; break;
        case 0x25: character[0] = 'k'; break;
        case 0x250000: character[0] = 'K'; break;
        case 0x26: character[0] = 'l'; break;
        case 0x260000: character[0] = 'L'; break;

        case 0x2C: character[0] = 'z'; break;
        case 0x2C0000: character[0] = 'Z'; break;
        case 0x2D: character[0] = 'x'; break;
        case 0x2D0000: character[0] = 'X'; break;
        case 0x2E: character[0] = 'c'; break;
        case 0x2E0000: character[0] = 'C'; break;
        case 0x2F: character[0] = 'v'; break;
        case 0x2F0000: character[0] = 'V'; break;
        case 0x30: character[0] = 'b'; break;
        case 0x300000: character[0] = 'B'; break;
        case 0x31: character[0] = 'n'; break;
        case 0x310000: character[0] = 'N'; break;
        case 0x32: character[0] = 'm'; break;
        case 0x320000: character[0] = 'M'; break;

        case 0x29: character[0] = '`'; break;
        case 0x290000: character[0] = '?'; break;
        case 0x2: character[0] = '1'; break;
        case 0x20000: character[0] = '!'; break;
        case 0x3: character[0] = '2'; break;
        case 0x30000: character[0] = '"'; break;
        case 0x4: character[0] = '3'; break;
        case 0x40000: character[0] = '?'; break;
        case 0x5: character[0] = '4'; break;
        case 0x50000: character[0] = '$'; break;
        case 0x6: character[0] = '5'; break;
        case 0x60000: character[0] = '%'; break;
        case 0x7: character[0] = '6'; break;
        case 0x70000: character[0] = '^'; break;
        case 0x8: character[0] = '7'; break;
        case 0x80000: character[0] = '&'; break;
        case 0x9: character[0] = '8'; break;
        case 0x90000: character[0] = '*'; break;
        case 0xA: character[0] = '9'; break;
        case 0xA0000: character[0] = '('; break;
        case 0xB: character[0] = '0'; break;
        case 0xB0000: character[0] = ')'; break;

        case 0x27: character[0] = ';'; break;
        case 0x270000: character[0] = ':'; break;
        case 0x28: character[0] = '\''; break;
        case 0x280000: character[0] = '@'; break;
        case 0x2B: character[0] = '#'; break;
        case 0x2B0000: character[0] = '~'; break;
        case 0x33: character[0] = ','; break;
        case 0x330000: character[0] = '<'; break;
        case 0x34: character[0] = '.'; break;
        case 0x340000: character[0] = '>'; break;
        case 0x35: character[0] = '/'; break;
        case 0x350000: character[0] = '?'; break;
        case 0x0C: character[0] = '-'; break;
        case 0x0C0000: character[0] = '_'; break;
        case 0x0D: character[0] = '='; break;
        case 0x0D0000: character[0] = '+'; break;
        case 0x1A: character[0] = '['; break;
        case 0x1A0000: character[0] = '{'; break;
        case 0x1B: character[0] = ']'; break;
        case 0x1B0000: character[0] = '}'; break;

        case 0x0E: character[0] = '\b'; break; //Backspace
        case 0x0F: character[0] = '\t'; break; //Tabulator
        case 0x1C: character[0] = '\n'; break; //Enter
        case 0x39: character[0] = ' '; break;  //Space

        case 0x0E0000: character[0] = '\b'; break; //Backspace (with shift)
        case 0x0F0000: character[0] = '\t'; break; //Tabulator (with shift)
        case 0x1C0000: character[0] = '\n'; break; //Enter (with shift)
        case 0x390000: character[0] = ' '; break;  //Space (with shift)

        default: character[0] = '?';
                int keyboardCode = shiftedScanCode;
                char snum[33];
                itoa(keyboardCode, snum);
                Print(snum);
                break;
      }

      character[1] = 0;

      Print(character);
    }
        }

        if(handlerNum >= 32 && handlerNum < 48)
        {
                DisplayColourArea(0x4, 0xF, handlerNum, 1);

                if(handlerNum >= 40)
                {
                        outb(0xA0, 0x20);
                }
                outb(0x20, 0x20);

       DisplayColourArea(0x5, 0xF, handlerNum, 1);
        }
}


void itoa(int i, char *p){
    char const digit[] = "0123456789";
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
}


