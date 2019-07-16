#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//欢迎界面
void WelcomeMenu() {
	printf("---------------服装销售系统-----------\n");
	printf("系统功能说明:\n");
	printf("   管理员功能:\n");
	printf("       (1)自身密码修改\n");
	printf("       (2)用户信息管理:添加,修改,删除,查询\n");
	printf("       (3)商品信息管理:添加,修改,查询,删除\n");
	printf("       (4)退出登陆系统\n");
	printf("   店长功能:\n");
	printf("       (1)自身密码修改\n");
	printf("       (2)商品信息管理:添加,修改,查询,删除\n");
	printf("       (3)销售报表显示:日销售报表,月销售报表,销售员销售报表\n");
	printf("       (4)退出登陆系统\n");
	printf("   销售员功能:\n");
	printf("       (1)商品浏览,查询,商品销售\n");
	printf("       (2)自己商品销售报表显示:日销售报表,月销售报表\n");
	printf("       (3)退出登陆系统\n");
	printf("--------------谢谢使用--------------------\n");
	printf("（注：管理员，店长，用户登陆的账号分别是admin,boss,sell初始密码和账号一致)\n");
}

//所有用户身份调用的登陆函数
void SystemLogin() {                 
	char userName[20], password[20];
	int isLogin = 0;
	SystemUser *tmpUser;
	printf("请输入你的系统用户帐号:");
	scanf("%s", userName);
	printf("\n请输入你的系统用户密码:");
	scanf("%s", password);

	tmpUser = pSystemUserHead;
	while (NULL != tmpUser) {
		if (0 == strcmp(tmpUser->userName, userName)) {
			if (0 == strcmp(tmpUser->password, password)) {
				isLogin = 1;
				strcpy(currentUser, tmpUser->userName);
				currentUserType = tmpUser->userType;
				switch (currentUserType) {
				case ADMIN_USER_TYPE:
					AdminOperationMenu();
					break;
				case BOSS_USER_TYPE:
					BossOperationMenu();
					break;
				case SELL_USER_TYPE:
					SellOperationMenu();
					break;
				default:
					break;
				}
			}
			else {
				printf("对不起,你输入的密码错误!\n");
				SystemLogin();                                           //用户名正确,密码错误
			}
		}
		tmpUser = tmpUser->next;
	}
	if (isLogin != 1) {
		printf("对不起,该用户不存在\n");                           //遍历了所有用户都没有找到用户
		SystemLogin();
	}
}

//密码修改函数
void ChangePassword() {
	char newPassword1[20], newPassword2[20];
	SystemUser *tmpUser;
	printf("请输入你的新密码:");
	scanf("%s", newPassword1);
	printf("请再次输入你的新密码:");
	scanf("%s", newPassword2);
	if (0 != strcmp(newPassword1, newPassword2)) {
		printf("对不起,你两次输入的密码不一致,修改失败!\n");
		return;
	}

	tmpUser = pSystemUserHead;
	while (NULL != tmpUser) {
		if (0 == strcmp(tmpUser->userName, currentUser)) {
			strcpy(tmpUser->password, newPassword1);
			printf("密码修改成功!\n");
			break;
		}
		tmpUser = tmpUser->next;
	}
}

//用户信息查看函数//
void UserInfoView() {
	SystemUser *tmpUser;
	tmpUser = pSystemUserHead;
	printf("亲爱的管理员%s,你好，你查看的所有用户信息如下:\n", currentUser);
	printf("用户名\t密码\t用户类型(1代表管理员,2代表店长，3代表销售员)\n");
	while (NULL != tmpUser) {
		printf("%s\t%s\t%d\n", tmpUser->userName, tmpUser->password, tmpUser->userType);
		tmpUser = tmpUser->next;
	}
}
//用户信息添加函数//
void UserInfoAdd() {
	SystemUser tmpUser;
	printf("亲爱的管理员%s,请依次输入用户信息:\n", currentUser);
	printf("用户名:");
	scanf("%s", tmpUser.userName);
	printf("用户密码:");
	scanf("%s", tmpUser.password);
	printf("用户类型(1代表管理员,2代表店长,3代表销售员):");
	scanf("%d", &tmpUser.userType);
	tmpUser.next = NULL;

	if (FUNCTION_SUCCESS == AddUser(&tmpUser))
		printf("用户信息添加成功!\n");

}
//用户信息修改函数//
void UserInfoModify() {
	char userName[20];
	SystemUser *pUser;
	printf("亲爱的管理员%s,请输入要修改的用户帐号:\n", currentUser);
	scanf("%s", userName);
	pUser = pSystemUserHead;
	while (NULL != pUser) {
		if (0 == strcmp(pUser->userName, userName)) {
			printf("请输入新的帐号:");
			scanf("%s", pUser->userName);
			printf("请输入新的密码:");
			scanf("%s", pUser->password);
			printf("请输入新的用户类型(1代表管理员,2代表店长,3代表销售员):");
			scanf("%d", &pUser->userType);
			printf("用户信息修改成功\n");
			return;
		}
		pUser = pUser->next;
	}
	printf("对不起,没有你查找的用户信息!\n");
}
//用户信息删除函数//
void UserInfoDelete() {

	SystemUser *pUserA, *pUserB;
	char userName[20];
	printf("亲爱的管理员%s朋友,你好,你现在进入的用户信息删除功能:\n", currentUser);
	printf("请输入你要删除的用户名:\n");
	scanf("%s", userName);
	pUserA = pUserB = pSystemUserHead;    //pUserB指向要删除的记录,pUserA指向前一条记录
	if (NULL == pUserB) return;
	while (NULL != pUserB) {
		if (0 == strcmp(userName, pUserB->userName)) {
			if (pUserB == pSystemUserHead && pUserB->next == NULL) {    //如果系统只有一条商品信息
				free(pSystemUserHead);
				pSystemUserHead = NULL;
				printf("用户信息删除成功!\n");
				return;
			}
			pUserA->next = pUserB->next;
			if (pSystemUserHead == pUserB)
				pSystemUserHead = pUserB->next;
			free(pUserB);
			printf("用户信息删除成功！\n");
			return;
		}
		else {
			pUserA = pUserB;
			pUserB = pUserB->next;
		}
	}
	printf("对不起，不存在该帐号的用户信息!");
}
//用户信息管理:添加,修改,删除,查询//
void UserManage() {                 //用户信息函数//
	int select;
	//管理员显示模块//
	while (1) {
		printf("亲爱的管理员%s同志,你目前进入的是用户信息管理功能:\n", currentUser);
		printf("  (1)用户信息查看\n");
		printf("  (2)用户信息添加\n");
		printf("  (3)用户信息修改\n");
		printf("  (4)用户信息删除\n");
		printf("  (5)返回上级菜单\n");
		printf("  (6)退出登陆系统\n");
		printf("请输入上面功能对应的序号进行功能选择:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			UserInfoView();     //调用用户信息查看的函数//
			continue;
		case 2:
			UserInfoAdd();       //调用用户信息添加函数//
			continue;
		case 3:
			UserInfoModify();    //调用用户信息修改函数//
			continue;
		case 4:
			UserInfoDelete();    //调用用户信息删除函数//
			continue;
		case 5:
			AdminOperationMenu();  //返回上级系统//
			break;
		case 6:
			ExitSystem();        //退出登陆//
			break;
		default:
			break;
		}
	}
}

//商品的查看函数//
void ProductsView() {
	Products *tmpProduct;
	int i;
	i = 1;
	tmpProduct = pProductHead;
	if (NULL == tmpProduct)
		printf("对不起,目前还没有商品信息");
	else {
		while (NULL != tmpProduct) {
			printf("第%d件商品信息如下:\n", i);
			printf("商品编号: %d\n", tmpProduct->productId);
			printf("商品名称: %s\n", tmpProduct->productName);
			printf("商品型号: %s\n", tmpProduct->productType);
			printf("商品厂家: %s\n", tmpProduct->productCompany);
			printf("商品价格: %f\n", tmpProduct->productPrice);
			printf("商品数量: %d\n", tmpProduct->productCount);
			printf("商品附加信息: %s\n", tmpProduct->memo);

			tmpProduct = tmpProduct->next;
			i++;
		}
	}
}
//商品查找函数//
void ProductFind() {
	Products *tmpProduct;
	int findWay, productId;
	char productName[20];
	printf("亲爱的%s朋友,你好,你现在进入的商品查询功能:\n", currentUser);
	printf("请选择查询方式: 1--按商品编号查询  2--按商品名称查询\n");
	scanf("%d", &findWay);
	tmpProduct = pProductHead;
	switch (findWay) {
	case 1:
		printf("请输入查询的商品编号:");
		scanf("%d", &productId);
		while (NULL != tmpProduct) {
			if (productId == tmpProduct->productId) {
				printf("你查询的商品编号为%d的商品信息如下:\n", productId);
				printf("  商品名称: %s\n", tmpProduct->productName);
				printf("  商品型号: %s\n", tmpProduct->productType);
				printf("  商品厂家: %s\n", tmpProduct->productCompany);
				printf("  商品价格: %f\n", tmpProduct->productPrice);
				printf("  商品数量: %d\n", tmpProduct->productCount);
				printf("  商品附加信息: %s\n", tmpProduct->memo);
				return;
			}
			tmpProduct = tmpProduct->next;
		}
		printf("对不起,不存在该商品编号的商品!\n");
		break;
	case 2:
		printf("请输入查询的商品名称:");
		scanf("%s", productName);
		while (NULL != tmpProduct) {
			if (0 == strcmp(tmpProduct->productName, productName)) {
				printf("你要查询的商品名称为%s的商品信息如下:\n", productName);
				printf("  商品名称: %s\n", tmpProduct->productName);
				printf("  商品型号: %s\n", tmpProduct->productType);
				printf("  商品厂家: %s\n", tmpProduct->productCompany);
				printf("  商品价格: %f\n", tmpProduct->productPrice);
				printf("  商品数量: %d\n", tmpProduct->productCount);
				printf("  商品附加信息: %s\n", tmpProduct->memo);
				return;
			}
			tmpProduct = tmpProduct->next;
		}
		printf("对不起,不存在该商品编号的商品!\n");
		break;
	default:
		break;
	}
}
//商品添加函数//
void InputAndAddProduct() {
	Products product;
	printf("亲爱的%s朋友,你好,请依次输入新商品的信息:\n", currentUser);
	printf("商品名称:");
	scanf("%s", product.productName);
	printf("商品型号:");
	scanf("%s", product.productType);
	printf("商品制造商:");
	scanf("%s", product.productCompany);
	printf("商品价格:");
	scanf("%f", &product.productPrice);
	printf("商品数量:");
	scanf("%d", &product.productCount);
	printf("商品附加信息:");
	scanf("%s", product.memo);
	product.next = NULL;

	if (FUNCTION_SUCCESS == AddProduct(&product))
		printf("商品信息添加成功!\n");
}
//商品修改函数//
void ModifyProduct() {
	int productId;                                //待修改的商品编号
	Products *tmpProduct;
	printf("亲爱的%s朋友,你好,你现在进入的商品信息修改功能:\n", currentUser);
	printf("请输入要修改的商品编号:");
	scanf("%d", &productId);
	tmpProduct = pProductHead;
	if (NULL == tmpProduct) return;
	while (NULL != tmpProduct) {
		if (productId == tmpProduct->productId) {
			printf("商品编号%d的商品信息如下:\n", productId);
			printf("  商品名称: %s\n", tmpProduct->productName);
			printf("  商品型号: %s\n", tmpProduct->productType);
			printf("  商品厂家: %s\n", tmpProduct->productCompany);
			printf("  商品价格: %f\n", tmpProduct->productPrice);
			printf("  商品数量: %d\n", tmpProduct->productCount);
			printf("  商品附加信息: %s\n", tmpProduct->memo);

			printf("下面请对照修改该商品的相应信息:\n");
			printf("新的商品名称: ");
			scanf("%s", tmpProduct->productName);
			printf("新的商品型号: ");
			scanf("%s", tmpProduct->productType);
			printf("新的商品厂家: ");
			scanf("%s", tmpProduct->productCompany);
			printf("新的商品价格: ");
			scanf("%f", &tmpProduct->productPrice);
			printf("新的商品数量: ");
			scanf("%d", &tmpProduct->productCount);
			printf("新的商品附加信息: ");
			scanf("%s", tmpProduct->memo);

			printf("商品信息修改成功!\n");

			break;
		}
		tmpProduct = tmpProduct->next;
	}
}
//商品删除函数//
void DeleteProduct() {
	int productId = 0;
	Products *tmpProductA, *tmpProductB;
	printf("亲爱的%s朋友,你好,你现在进入的商品删除功能:\n", currentUser);
	printf("请输入你要删除的商品编号:\n");
	scanf("%d", &productId);
	tmpProductA = tmpProductB = pProductHead;    //tmpProductB指向要删除的记录，tmpProductA指向前一条记录
	if (NULL == tmpProductB) return;
	while (NULL != tmpProductB) {
		if (tmpProductB->productId == productId) {
			if (tmpProductB == pProductHead && tmpProductB->next == NULL) { //如果系统只有一条商品信息
				free(pProductHead);
				pProductHead = NULL;
				printf("商品信息删除成功!\n");
				return;
			}
			tmpProductA->next = tmpProductB->next;
			if (pProductHead == tmpProductB)
				pProductHead = tmpProductB->next;
			free(tmpProductB);
			printf("商品信息删除成功！\n");
			return;
		}
		else {
			tmpProductA = tmpProductB;
			tmpProductB = tmpProductB->next;
		}
	}
	printf("对不起，不存在该商品编号的信息!");
}

//商品管理模块//
void ProductsManage() {
	int select;
	while (1) {
		printf("亲爱的%s朋友,你好,你现在进入的是商品管理功能,你可以选择以下功能:\n", currentUser);
		printf("   (1)商品信息查看\n");
		printf("   (2)商品信息查找\n");
		printf("   (3)商品信息添加\n");
		printf("   (4)商品信息修改\n");
		printf("   (5)商品信息删除\n");
		printf("   (6)返回上一级菜单\n");
		printf("   (7)退出登陆系统\n");
		printf("请选择应的操作编号:");
		scanf("%d", &select);
		switch (select) {
		case 1:
			ProductsView();   //调用商品查看函数//
			continue;
		case 2:
			ProductFind();    //调用商品信息查找函数//
			continue;
		case 3:
			InputAndAddProduct();  //调用商品添加函数//
			continue;
		case 4:
			ModifyProduct();     //调用商品修改函数//
			continue;
		case 5:
			DeleteProduct();   //调用删除商品信息函数//
			continue;
		case 6:
			switch (currentUserType) {   //返回上一级//
			case ADMIN_USER_TYPE:
				AdminOperationMenu();
				break;
			case BOSS_USER_TYPE:
				BossOperationMenu();
				break;
			case SELL_USER_TYPE:
				SellOperationMenu();
				break;
			default:
				break;
			}
			break;
		case 7:
			ExitSystem();
			break;
		default:
			break;
		}
	}
}

//管理员欢迎界面函数
void AdminOperationMenu() {
	int select;
	while (1) {
		printf("亲爱的管理员%s同志,欢迎使用本系统,你拥有下面所有功能:\n", currentUser);
		printf("  (1)自身密码修改\n");
		printf("  (2)用户信息管理:添加,修改,查询,删除\n");
		printf("  (3)商品信息管理:添加,修改,查询,删除\n");
		printf("  (4)退出系统\n");
		printf("请输入上面功能对应的序号进行功能选择:");
		scanf("%d", &select);
		switch (select) {
		case 1:
			ChangePassword();
			continue;
		case 2:
			UserManage();
			continue;
		case 3:
			ProductsManage();
			continue;
		case 4:
			ExitSystem();
			break;
		default:
			break;
		}
	}
}

//日销售函数的统计//
void ShowDaySellReport() {
	int year, month, day;
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("你好%s:当前功能将进行日销售报表显示\n", currentUser);
	printf("请输入销售时间年份:");
	scanf("%d", &year);
	printf("请输入销售时间月份:");
	scanf("%d", &month);
	printf("请输入销售时间号数:");
	scanf("%d", &day);

	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		if (year == tmpSellInfo->year &&
			month == tmpSellInfo->month &&
			day == tmpSellInfo->day &&
			((SELL_USER_TYPE == currentUserType) ? (0 == strcmp(tmpSellInfo->userName, currentUser)) : 1)) {
			rsCount++;
			printf("符合条件的第%d条商品销售记录信息如下:\n", rsCount);
			printf(" 销售编号:%d\n", tmpSellInfo->saleId);
			printf(" 产品编号:%d\n", tmpSellInfo->productId);
			getProductNameById(tmpSellInfo->productId, productName);
			printf(" 产品名称:%s\n", productName);
			onePrice = getPriceById(tmpSellInfo->productId);
			printf(" 商品单价:%f\n", onePrice);
			printf(" 销售数量:%d\n", tmpSellInfo->sellCount);
			printf(" 销售员:%s\n", tmpSellInfo->userName);
			printf(" 销售时间:%d年%d月%d日\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
			totalPrice += onePrice * tmpSellInfo->sellCount;
		}
		tmpSellInfo = tmpSellInfo->next;
	}
	printf("总共有%d条符合条件的记录,销售总价%f元\n", rsCount, totalPrice);
}
//月销售量函数统计//
void ShowMonthSellReport() {
	int year, month;
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("你好%s:当前功能将进行月销售报表显示\n", currentUser);
	printf("请输入销售时间年份:");
	scanf("%d", &year);
	printf("请输入销售时间月份:");
	scanf("%d", &month);

	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		if (year == tmpSellInfo->year &&
			month == tmpSellInfo->month &&
			((SELL_USER_TYPE == currentUserType) ? (0 == strcmp(tmpSellInfo->userName, currentUser)) : 1)) {
			rsCount++;
			printf("符合条件的第%d条商品销售记录信息如下:\n", rsCount);
			printf(" 销售编号:%d\n", tmpSellInfo->saleId);
			printf(" 产品编号:%d\n", tmpSellInfo->productId);
			getProductNameById(tmpSellInfo->productId, productName);
			printf(" 产品名称:%s\n", productName);
			onePrice = getPriceById(tmpSellInfo->productId);
			printf(" 商品单价:%f\n", onePrice);
			printf(" 销售数量:%d\n", tmpSellInfo->sellCount);
			printf(" 销售员:%s\n", tmpSellInfo->userName);
			printf(" 销售时间:%d年%d月%d日\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
			totalPrice += onePrice * tmpSellInfo->sellCount;
		}
		tmpSellInfo = tmpSellInfo->next;
	}
	printf("总共有%d条符合条件的记录,销售总价%f元\n", rsCount, totalPrice);
}
//显示销售员的业绩//
void ShowEmployeeSellReport() {
	char userName[20];
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("你好%s:当前功能将进行销售员销售报表显示\n", currentUser);
	printf("请输入销售员的帐户名:");
	scanf("%s", userName);
	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		if (0 == strcmp(userName, tmpSellInfo->userName)) {
			rsCount++;
			printf("符合条件的第%d条商品销售记录信息如下:\n", rsCount);
			printf(" 销售编号:%d\n", tmpSellInfo->saleId);
			printf(" 产品编号:%d\n", tmpSellInfo->productId);
			getProductNameById(tmpSellInfo->productId, productName);
			printf(" 产品名称:%s\n", productName);
			onePrice = getPriceById(tmpSellInfo->productId);
			printf(" 商品单价:%f\n", onePrice);
			printf(" 销售数量:%d\n", tmpSellInfo->sellCount);
			printf(" 销售员:%s\n", tmpSellInfo->userName);
			printf(" 销售时间:%d年%d月%d日\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
			totalPrice += onePrice * tmpSellInfo->sellCount;
		}
		tmpSellInfo = tmpSellInfo->next;
	}
	printf("总共有%d条符合条件的记录,销售总价%f元\n", rsCount, totalPrice);
}
//显示所有销售员的业绩//
void ShowAllSellReport() {
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("你好%s:当前功能将进行所有销售报表显示\n", currentUser);
	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		rsCount++;
		printf("第%d条商品销售记录信息如下:\n", rsCount);
		printf(" 销售编号:%d\n", tmpSellInfo->saleId);
		printf(" 产品编号:%d\n", tmpSellInfo->productId);
		getProductNameById(tmpSellInfo->productId, productName);
		printf(" 产品名称:%s\n", productName);
		onePrice = getPriceById(tmpSellInfo->productId);
		printf(" 商品单价:%f\n", onePrice);
		printf(" 销售数量:%d\n", tmpSellInfo->sellCount);
		printf(" 销售员:%s\n", tmpSellInfo->userName);
		printf(" 销售时间:%d年%d月%d日\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
		totalPrice += onePrice * tmpSellInfo->sellCount;

		tmpSellInfo = tmpSellInfo->next;
	}
	printf("总共有%d条符合条件的记录,销售总价%f元\n", rsCount, totalPrice);
}
//销售报表显示//
void ReportPrint() {
	int select = 0;
	if (SELL_USER_TYPE != currentUserType) {
		while (1) {
			printf("亲爱的朋友%s,你好，你现在进入的是销售报表功能界面:\n", currentUser);
			printf("  (1)所有商品销售情况\n");
			printf("  (2)商品日销售报表\n");
			printf("  (3)商品月销售报表\n");
			printf("  (4)销售员销售报表\n");
			printf("  (5)返回上级菜单\n");
			printf("  (6)退出登陆系统\n");
			printf("请选择对应的功能号:");
			scanf("%d", &select);
			switch (select) {
			case 1:
				ShowAllSellReport();
				continue;
			case 2:
				ShowDaySellReport();
				continue;
			case 3:
				ShowMonthSellReport();
				continue;
			case 4:
				ShowEmployeeSellReport();
				continue;
			case 5:
				switch (currentUserType) {
				case ADMIN_USER_TYPE:
					AdminOperationMenu();
					break;
				case BOSS_USER_TYPE:
					BossOperationMenu();
					break;
				default:
					break;
				}
				break;
			case 6:
				ExitSystem();
				break;
			default:
				break;
			}
		}
	}
	else {
		while (1) {
			printf("亲爱的销售员%s,你好，你现在进入的是销售报表功能界面:\n", currentUser);
			printf("  (1)查看自己日销售报表\n");
			printf("  (2)查看自己月销售报表\n");
			printf("  (3)返回上级菜单\n");
			printf("  (4)退出登陆系统");
			printf("请选择相应的功能号:");
			scanf("%d", &select);
			switch (select) {
			case 1:
				ShowDaySellReport();
				continue;
			case 2:
				ShowMonthSellReport();
				continue;
			case 3:
				SellOperationMenu();
				break;
			case 4:
				ExitSystem();
				break;
			default:
				break;
			}
		}
	}
}

//店长欢迎界面//
void BossOperationMenu() {
	int select;
	while (1) {
		printf("亲爱的店长%s同志,欢迎使用本系统,你拥有下面所有功能:\n", currentUser);
		printf("  (1)自身密码修改\n");
		printf("  (2)商品信息管理:添加,修改,查询,删除\n");
		printf("  (3)销售报表显示:日报表,月报表,商品销售量报表,销售员业绩报表\n");
		printf("  (4)退出系统\n");
		printf("请输入上面功能对应的序号进行功能选择:");
		scanf("%d", &select);
		switch (select) {
		case 1:
			ChangePassword();
			break;
		case 2:
			ProductsManage();
			break;
		case 3:
			ReportPrint();
			break;
		case 4:
			ExitSystem();;
			break;
		default:
			break;
		}
	}
}

//销售员管理模块//
void SellOperationMenu() {
	int select;
	while (1) {
		printf("亲爱的销售员%s同志,欢迎使用本系统,你拥有下面所有功能:\n", currentUser);
		printf("  (1)商品浏览\n");
		printf("  (2)商品查询\n");
		printf("  (3)商品销售\n");
		printf("  (4)报表查看\n");
		printf("  (5)退出登陆系统\n");
		printf("请输入上面功能对应的序号进行功能选择:");
		scanf("%d", &select);
		switch (select) {
		case 1:
			ProductsView();
			continue;
		case 2:
			ProductFind();
			continue;
		case 3:
			ProductsSell();
			continue;
		case 4:
			ReportPrint();
			continue;
		case 5:
			ExitSystem();
			break;
		default:
			break;
		}
	}
}
