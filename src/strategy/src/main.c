#include "stdio.h"
#include "inc/type_def.h"

typedef uint16_t (*get_result_t)(uint16_t, uint16_t);

typedef struct
{
	uint16_t number_a;
	uint16_t number_b;
	get_result_t get_result;
} operation_t;


typedef operation_t (*create_operate_t)(uint16_t);

typedef struct
{
	create_operate_t create_operate;
} operation_factory_t;


typedef struct
{
	uint8_t oper_flag;
	operation_factory_t operation_create;
	operation_t operation;
} operation_context_t;
/**
 * code
 */

static uint16_t add_alg(uint16_t para1, uint16_t para2)
{
	return (para1 + para2);
}

static uint16_t minus_alg(uint16_t para1, uint16_t para2)
{
	return (para1 - para2);
}

static uint16_t multi_alg(uint16_t para1, uint16_t para2)
{
	return (para1 * para2);
}

static uint16_t divide_alg(uint16_t para1, uint16_t para2)
{
	return (para1 / para2);
}

operation_context_t create_operate_context(uint8_t flag)
{
	operation_context_t operation_context;
	operation_context.oper_flag = flag;
	switch (flag)
	{
	case '+':
		operation_context.operation.get_result = add_alg;
		break;

	case '-':
		operation_context.operation.get_result = minus_alg;
		break;

	case '*':
		operation_context.operation.get_result = multi_alg;
		break;

	case '/':
		operation_context.operation.get_result = divide_alg;
		break;

	default:
		break;
	}
	return operation_context;
}

uint16_t main(int argc, char const *argv[])
{
	operation_context_t operation_context;

	printf("please input operation flag :\n");
	scanf("%c", &operation_context.oper_flag);
	operation_context = create_operate_context(operation_context.oper_flag);

	printf("please input nubmer a :\n");
	scanf("%d", &operation_context.operation.number_a );
	printf("please input nubmer b :\n");
	scanf("%d", &operation_context.operation.number_b);

	uint16_t resule = operation_context.operation.get_result(operation_context.operation.number_a,
	                  operation_context.operation.number_b);

	printf("resule is  :%d\n", resule);
	return 0;
}