#include <stdio.h>

int main(int argc, char *argv[]) 
{
	while(1)
	{
		printf("计算拍拖几天可以啪啪啪, 纯理论, 只作参考\n");
		double W_age, W_apperance, W_part, M_apperance, M_property;
		
		printf("女方年龄(年龄)40岁以上女性本公式不适用\n");
		scanf("%lf", & W_age);

		printf("女方外貌(外观)10为满分\n");
		scanf("%lf", & W_apperance);

		printf("男方外貌(外观)10为满分\n");
		scanf("%lf", & M_apperance);

		printf("男方资产(价值), 每万元为1个单位, 不置上限, 物业及汽车亦计算在内\n");
		scanf("%lf", & M_property);

		printf("女方曾有性行为的男性数目(性伴侣)\n");
		scanf("%lf", & W_part);

		double day = 0;
		day = ((40 - W_age)*(40 - W_age) + W_apperance * W_apperance * W_apperance) * 10 / ((M_apperance * M_apperance + M_property / 10) * (W_part + 1) * (W_part + 1));

		printf("交往 %lf 天可以啪啪啪!!! 本轮结束\n", day);
	}
}