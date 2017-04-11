#include "stdio.h"
#include "inc/type_def.h"

typedef uint16_t (*get_result_t)(uint16_t, uint16_t);

typedef struct
{
	uint16_t number_a;
	uint16_t number_b;
	uint8_t oper_flag;
	get_result_t get_result;
} operation_t;


typedef operation_t (*create_operate_t)(uint16_t);

typedef struct
{
	create_operate_t create_operate;
} operation_factory_t;

/**
 * code
 */

uint16_t add_alg(uint16_t para1, uint16_t para2)
{
	return (para1 + para2);
}

uint16_t minus_alg(uint16_t para1, uint16_t para2)
{
	return (para1 - para2);
}

uint16_t multi_alg(uint16_t para1, uint16_t para2)
{
	return (para1 * para2);
}

uint16_t divide_alg(uint16_t para1, uint16_t para2)
{
	return (para1 / para2);
}

operation_t create_operate_alg(uint16_t flag)
{
	operation_t operation_tmp;

	switch (flag)
	{
	case '+':
		operation_tmp.get_result = add_alg;
		break;

	case '-':
		operation_tmp.get_result = minus_alg;
		break;

	case '*':
		operation_tmp.get_result = multi_alg;
		break;

	case '/':
		operation_tmp.get_result = divide_alg;
		break;

	default:
		break;
	}
	return operation_tmp;
}

uint16_t main(int argc, char const *argv[])
{
	uint8_t oper_flag = 0;

	operation_factory_t operation_factory;
	operation_factory.create_operate = create_operate_alg;

	operation_t oper ;
	printf("please input operation flag :\n");
	scanf("%c", &oper.oper_flag);
	oper = operation_factory.create_operate(oper.oper_flag);


	printf("please input nubmer a :\n");
	scanf("%d", &oper.number_a );
	printf("please input nubmer b :\n");
	scanf("%d", &oper.number_b);
	uint16_t resule = oper.get_result(oper.number_a, oper.number_b);

	printf("resule is  :%d\n", resule);
	return 0;
}