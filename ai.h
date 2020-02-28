#pragma once

// AI.H header

#ifndef _IOSTREAM_
#define _IOSTREAM_ 
#endif

#ifndef _CSTRING_
#define _CSTRING_
#endif



/*************
 *	制作：Junhao
 *	联系：liujunhao139@gmail.com
 *	
 
 *	目的：
 

 *	当前*
			遍历字串符并著顺序判断是否数字或x。并根据a、b和c的值判断将把获得到的值赋给谁。
	
	1级（更新）
			遍历字符串并逐顺序判断是否数字，且数字后是否数字，若数字后还有数字那么两个数字合并为
			一个数字。之后再判断数字后的x是二级，一级还是不确定数。再确定等号何时出现，确定如何
			计算。并把结果输出。
	2级（更新）
			满足其他函数。
	3级（更新）
			判断等号位置并根据等号计算a、b和c。
 	
 ************/


struct OPERATION { double a;	double b;	double c; };

double		geta(char*);		// 获得a元素
double		getb(char*);		// 获得b元素
double		getc(char*);		// 获得c元素

OPERATION	comp_getAll(const char*);	// 一次性获取完整算式
OPERATION	inco_getAll(char*);	// 一次性获取非完整算式


OPERATION comp_getAll(const char* operation) {
	int strLength = strlen(operation); // 获得operation长度
	double numberA = 0;
	double numberB = 0;
	double numberC = 0;

	char* reserved = new char[strLength];	// 备用字串符

	for (int length = 0; length < strLength; length++) { // 遍历operation字符
		char gotChar = operation[length];

		reserved[length] = gotChar;

		if (gotChar == 'x') {
			if (numberA == 0) {	// 判断x是否a，且是不是单x
				numberA = 1;
			} else if (numberB == 0) { 
				numberB = 1;
			} else if (numberC == 0) {
				numberC = 1;
			} else {	// 若不是a、b或c，即为错误
				std::cout << "ERROR: x with no use." << std::endl;
				break;
			}
		}
		if (gotChar > 0x2F || gotChar < 0x3A) { // 判断是否数字
			if (numberA == 0) {
				if (((int)gotChar - 0x30) != 0) {	// 判断是否为0
					numberA = (int)gotChar - 0x30;
				} else {
					std::cout << "ERROR: num value of 0." << std::endl;	// 危险！！！
					break;
				}
			} else if (numberB == 0) {
				if (((int)gotChar - 0x30) != 0) {	// 判断是否为0
					numberB = (int)gotChar - 0x30;
				}
				else {
					std::cout << "ERROR: num value of 0." << std::endl; // 危险！！！
					break;
				}
			} else if (numberC == 0) {
				if (((int)gotChar - 0x30) != 0) {	// 判断是否为0
					numberC = (int)gotChar - 0x30;
				}
				else {
					std::cout << "ERROR: num value of 0." << std::endl;	// 危险！！！
					break;
				} 
			}
		}
	}
	return { numberA, numberB, numberC };
}