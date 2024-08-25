#include<cstdio>
#include<climits>
//(1)	int absVal(int x);      返回 x 的绝对值
//仅使用 !、 ~、 & 、^ 、 | 、 + 、 << 、 >> ， 运算次数不超过 10次
int absVal(int x)
{//x  -x=~x+1
	int mask = x >> 31;//正则全为0，负全为1
     return (x ^ mask) + (~mask) + 1;
	/*另一种解法，利用x, x - 2 * x
  int b;
  b = (x >> 31) & (x << 1);
  return x + (~b) + 1;*/
}
int absVal_standard(int x) { return (x < 0) ? -x : x; }
//(2)	int negate(int x);      不使用负号，实现 - x
int negate(int x)
{
	return ~x + 1;
}
int negate_standard(int x) { return -x; }

//(3)	int bitAnd(int x, int y);  仅使用 ~和 | ，实现&
int bitAnd(int x, int y)
{
	return ~(~x | ~y);
}
int bitAnd_standard(int x, int y) { return x & y; }
//(4)	int bitOr(int x, int y);    仅使用 ~和 & ，实现 |
int bitOr(int x, int y)
{
	return ~(~x & ~y);
}
int bitOr_standard(int x, int y) { return x | y; }
//(5)	int bitXor(int x, int y);   仅使用 ~和 & ，实现^
int bitXor(int x, int y)
{//x^y = (x&~y)|(~x&y)
	return ~(~(x & ~y) & ~(~x & y));
}
int bitXor_standard(int x, int y) { return x ^ y; }
//(6)	int isTmax(int x);    判断x是否为最大的正整数（7FFFFFFF），
//只能使用 !、 ~、 & 、^ 、 | 、 +
int isTmax(int x)
{//只有Tmax满足x+1与~x相等
	return !(((x+1)^(~x))|(!(~x)));
}
int isTmax_standard(int x) { return x==0x7FFFFFFF; }
//(7)	int bitCount(int x);   统计x的二进制表示中 1 的个数
//只能使用，!~&^| +<< >> ，运算次数不超过 40次
int bitCount(int x)
{//注意加括号，+优先级高于&
		int a = 0x11 | (0x11 << 8);//00010001 00010001
		int mask = a | (a << 16);//00010001 00010001 00010001 00010001
		int s;
		s = (x & mask) + ((x >> 1) & mask) + ((x >> 2) & mask) + ((x >> 3) & mask);
		//此时32位的每连续四位所表示的无符号整数刚好为原x重对应四位中1的个数
		// 最大为0100,方便右移
		//将8个四位累加起来即可
		int b = 0xf | (0xf << 8);//00001111 00001111
		int mask2 = b | (b << 16);//00001111 00001111 00001111 0000 1111
		s = (s & mask2) + ((s >> 4) & mask2);
		//32位的连续8位
		//答案最大为32 可用8位二进制数表示，
		// 之后不用考虑干扰，直接加
		s = s + (s >> 16);
		s = s + (s >> 8);
		return s&(0xff);
}
int bitCount_standard(int x) {
	int result = 0;
	int i;
	for (i = 0; i < 32; i++)
		result += (x >> i) & 0x1;
	return result;
}
//(8)	int bitMask(int highbit, int lowbit); 产生从lowbit 到 highbit 全为1，其他位为0的数。例如bitMask(5, 3) = 0x38 ；要求只使用 !~&^| +<< >> ；运算次数不超过 16次。
int bitMask(int highbit, int lowbit)//111100001111
{//构造两个形如11111000类型的数并异或
	return (((~0) << highbit)<<1) ^ ((~0) << lowbit);
}
int bitMask_standard(int highbit, int lowbit)
{
	int result = 0;
	int i;
	for (i = lowbit; i <= highbit; i++)
		result |= 1 << i;
	return result;
}
//(9)	int addOK(int x, int y);  当x + y 会产生溢出时返回1，否则返回 0
//仅使用 !、 ~、 & 、 ^ 、 | 、 + 、 << 、 >> ， 运算次数不超过 20次
int addOK(int x, int y)
{//溢出时正正得负和负负得正,溢出时返回1
	int ans = x + y;
	return !!(((x & y & (~ans))| ((~x) & (~y) &ans)) >> 31);
}
int addOK_standard(int x, int y)
{
	long long lsum = (long long)x + y;
	return lsum != (int)lsum;
}
//(10)	int byteSwap(int x, int n, int m);  将x的第n个字节与第m个字节交换，返回交换后的结果。 n、m的取值在 0~3之间。
//例：byteSwap(0x12345678, 1, 3) = 0x56341278
//byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
//仅使用 !、 ~、 & 、 ^ 、 | 、 + 、 << 、 >> ， 运算次数不超过 25次
int byteSwap(int x, int n, int m)
{//分别取出除对应字节外其他字节都为0的三部分（第n个字节，第m个字节和其他部分之后移动n与m相加
	int max,mask_n,mask_m,mask_nm,ans,sub;
	int n8, m8;
	//n8 = n << 3;
	max = 255;
	mask_n = max<<(n<<3);
	mask_m = max<<(m<<3);
	mask_nm = mask_n | mask_m;//形如0000000011111111000011111111000
	sub = (m + ~n + 1)<<3;
	ans = (x& (~mask_nm)) | (x & mask_n)<<sub | ((x & mask_m)>>sub)&mask_n ;
    return ans;
}
int byteSwap_standard(int x, int n, int m)
{
	/* little endiamachine */
	/* least significant byte stored first */
	unsigned int nmask, mmask;
	switch (n) {
	case 0:
		nmask = x & 0xFF;
		x &= 0xFFFFFF00;
		break;
	case 1:
		nmask = (x & 0xFF00) >> 8;
		x &= 0xFFFF00FF;
		break;
	case 2:
		nmask = (x & 0xFF0000) >> 16;
		x &= 0xFF00FFFF;
		break;
	default:
		nmask = ((unsigned int)(x & 0xFF000000)) >> 24;
		x &= 0x00FFFFFF;
		break;
	}

	switch (m) {
	case 0:
		mmask = x & 0xFF;
		x &= 0xFFFFFF00;
		break;
	case 1:
		mmask = (x & 0xFF00) >> 8;
		x &= 0xFFFF00FF;
		break;
	case 2:
		mmask = (x & 0xFF0000) >> 16;
		x &= 0xFF00FFFF;
		break;
	default:
		mmask = ((unsigned int)(x & 0xFF000000)) >> 24;
		x &= 0x00FFFFFF;
		break;
	}

	nmask <<= 8 * m;
	mmask <<= 8 * n;

	return x | nmask | mmask;
}
void test(int(*myfuc)(int x), int (*stdfuc)(int x), int* data, int num)
{//测试函数，测试1个参数的函数
	int ans1, ans2;
	for (int i = 0; i < num; i++)
	{
		printf("测试点:%d   ", i + 1);
		ans1 = stdfuc(data[i]);
		ans2 = myfuc(data[i]);
		printf("data:%d 标准输出结果：%d 函数输出结果：%d",data[i], ans1, ans2);
		if (ans1 == ans2)
			printf(" 输出正确\n");
		else
			printf(" 输出错误\n");
	}
	printf("\n");
}
void test(int(*myfuc)(int ,int), int (*stdfuc)(int ,int), int data[][2], int num)//2 parameters
{//测试函数，测试2个参数的函数
	int ans1, ans2;
	for (int i = 0; i < num; i++)
	{
		printf("测试点:%d   ", i + 1);
		ans1 = stdfuc(data[i][0],data[i][1]);
		ans2 = myfuc(data[i][0],data[i][1]);
		printf("data:%d  %d 标准输出结果：%d 函数输出结果：%d", data[i][0],data[i][1], ans1, ans2);
		if (ans1 == ans2)
			printf(" 输出正确\n");
		else
			printf(" 输出错误\n");
	}
	printf("\n");
}
void test(int(*myfuc)(int, int,int), int (*stdfuc)(int, int,int), int data[][3], int num)//2 parameters
{//测试函数，测试3个参数的函数
	int ans1, ans2;
	for (int i = 0; i < num; i++)
	{
		printf("测试点:%d   ", i + 1);
		ans1 = stdfuc(data[i][0], data[i][1],data[i][2]);
		ans2 = myfuc(data[i][0], data[i][1],data[i][2]);
		printf("data:0x%x  %d %d 标准输出结果：0x%x 函数输出结果：0x%x", data[i][0], data[i][1], data[i][2],ans1, ans2);
		if (ans1 == ans2)
			printf(" 输出正确\n");
		else
			printf(" 输出错误\n");
	}
	printf("\n");
}
int main()
{
	printf("开始测试\n");
	int ans1, ans2;
	int test1[4] = { 5,-9,0,INT_MIN };
	int test2[4] = { 5,-9,0,INT_MIN };
	int test3[3][2] = { {842616,55231},{ -135469,-151561 },{0,31249} };
	int test4[3][2] = { {842616,55231},{ -135469,-151561 },{0,31249} };
	int test5[3][2] = { {842616,55231},{ -135469,-151561 },{0,31249} };
	int test6[3] = { 59531,INT_MAX,-1 };
	int test7[3] = { 0,INT_MIN,-1 };
	int test8[3][2] = { {3,0},{ 26,5 },{31,9} };
	int test9[3][2] = { {6551,-5651},{ 65,INT_MAX },{-9,INT_MIN} };
	int test10[3][3] = { {0xABCDEDCB,1,3},{ 0xABCDEDCB,1,1 },{0xABCDEDCB,0,2} };
	char str[11][100] = { " ","absVal", "negate", "bitAnd", "bitOr", "bitXor", "isTmax", "bitCount", "bitMask", "addOK", "byteSwap"};
	for (int i = 1; i <= 10; i++)
	{
		printf("测试函数%d: %s\n", i,str[i]);
		switch (i)
		{
		case 1:
			test(absVal, absVal_standard, test1, 4);
			break;
		case 2:
			test(negate, negate_standard, test2, 4);
			break;
		case 3:
			test(bitAnd, bitAnd_standard, test3, 3);
			break;
		case 4:
			test(bitOr, bitOr_standard, test4, 3);
			break;
		case 5:
			test(bitXor, bitXor_standard, test5, 3);
			break;
		case 6:
			test(isTmax, isTmax_standard, test6, 3);
			break;
		case 7:
			test(bitCount, bitCount_standard, test7, 3);
			break;
		case 8:
			test(bitMask, bitMask_standard, test8, 3);
			break;
		case 9:
			test(addOK, addOK_standard, test9, 3);
			break;
		case 10:
			test(byteSwap, byteSwap_standard, test10, 3);
			break;
		}
	}
	printf("测试结束\n");
	return 0;
}
	