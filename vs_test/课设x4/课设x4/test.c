#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//��ӭ����
void WelcomeMenu() {
	printf("---------------��װ����ϵͳ-----------\n");
	printf("ϵͳ����˵��:\n");
	printf("   ����Ա����:\n");
	printf("       (1)���������޸�\n");
	printf("       (2)�û���Ϣ����:���,�޸�,ɾ��,��ѯ\n");
	printf("       (3)��Ʒ��Ϣ����:���,�޸�,��ѯ,ɾ��\n");
	printf("       (4)�˳���½ϵͳ\n");
	printf("   �곤����:\n");
	printf("       (1)���������޸�\n");
	printf("       (2)��Ʒ��Ϣ����:���,�޸�,��ѯ,ɾ��\n");
	printf("       (3)���۱�����ʾ:�����۱���,�����۱���,����Ա���۱���\n");
	printf("       (4)�˳���½ϵͳ\n");
	printf("   ����Ա����:\n");
	printf("       (1)��Ʒ���,��ѯ,��Ʒ����\n");
	printf("       (2)�Լ���Ʒ���۱�����ʾ:�����۱���,�����۱���\n");
	printf("       (3)�˳���½ϵͳ\n");
	printf("--------------ллʹ��--------------------\n");
	printf("��ע������Ա���곤���û���½���˺ŷֱ���admin,boss,sell��ʼ������˺�һ��)\n");
}

//�����û���ݵ��õĵ�½����
void SystemLogin() {                 
	char userName[20], password[20];
	int isLogin = 0;
	SystemUser *tmpUser;
	printf("���������ϵͳ�û��ʺ�:");
	scanf("%s", userName);
	printf("\n���������ϵͳ�û�����:");
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
				printf("�Բ���,��������������!\n");
				SystemLogin();                                           //�û�����ȷ,�������
			}
		}
		tmpUser = tmpUser->next;
	}
	if (isLogin != 1) {
		printf("�Բ���,���û�������\n");                           //�����������û���û���ҵ��û�
		SystemLogin();
	}
}

//�����޸ĺ���
void ChangePassword() {
	char newPassword1[20], newPassword2[20];
	SystemUser *tmpUser;
	printf("���������������:");
	scanf("%s", newPassword1);
	printf("���ٴ��������������:");
	scanf("%s", newPassword2);
	if (0 != strcmp(newPassword1, newPassword2)) {
		printf("�Բ���,��������������벻һ��,�޸�ʧ��!\n");
		return;
	}

	tmpUser = pSystemUserHead;
	while (NULL != tmpUser) {
		if (0 == strcmp(tmpUser->userName, currentUser)) {
			strcpy(tmpUser->password, newPassword1);
			printf("�����޸ĳɹ�!\n");
			break;
		}
		tmpUser = tmpUser->next;
	}
}

//�û���Ϣ�鿴����//
void UserInfoView() {
	SystemUser *tmpUser;
	tmpUser = pSystemUserHead;
	printf("�װ��Ĺ���Ա%s,��ã���鿴�������û���Ϣ����:\n", currentUser);
	printf("�û���\t����\t�û�����(1�������Ա,2����곤��3��������Ա)\n");
	while (NULL != tmpUser) {
		printf("%s\t%s\t%d\n", tmpUser->userName, tmpUser->password, tmpUser->userType);
		tmpUser = tmpUser->next;
	}
}
//�û���Ϣ��Ӻ���//
void UserInfoAdd() {
	SystemUser tmpUser;
	printf("�װ��Ĺ���Ա%s,�����������û���Ϣ:\n", currentUser);
	printf("�û���:");
	scanf("%s", tmpUser.userName);
	printf("�û�����:");
	scanf("%s", tmpUser.password);
	printf("�û�����(1�������Ա,2����곤,3��������Ա):");
	scanf("%d", &tmpUser.userType);
	tmpUser.next = NULL;

	if (FUNCTION_SUCCESS == AddUser(&tmpUser))
		printf("�û���Ϣ��ӳɹ�!\n");

}
//�û���Ϣ�޸ĺ���//
void UserInfoModify() {
	char userName[20];
	SystemUser *pUser;
	printf("�װ��Ĺ���Ա%s,������Ҫ�޸ĵ��û��ʺ�:\n", currentUser);
	scanf("%s", userName);
	pUser = pSystemUserHead;
	while (NULL != pUser) {
		if (0 == strcmp(pUser->userName, userName)) {
			printf("�������µ��ʺ�:");
			scanf("%s", pUser->userName);
			printf("�������µ�����:");
			scanf("%s", pUser->password);
			printf("�������µ��û�����(1�������Ա,2����곤,3��������Ա):");
			scanf("%d", &pUser->userType);
			printf("�û���Ϣ�޸ĳɹ�\n");
			return;
		}
		pUser = pUser->next;
	}
	printf("�Բ���,û������ҵ��û���Ϣ!\n");
}
//�û���Ϣɾ������//
void UserInfoDelete() {

	SystemUser *pUserA, *pUserB;
	char userName[20];
	printf("�װ��Ĺ���Ա%s����,���,�����ڽ�����û���Ϣɾ������:\n", currentUser);
	printf("��������Ҫɾ�����û���:\n");
	scanf("%s", userName);
	pUserA = pUserB = pSystemUserHead;    //pUserBָ��Ҫɾ���ļ�¼,pUserAָ��ǰһ����¼
	if (NULL == pUserB) return;
	while (NULL != pUserB) {
		if (0 == strcmp(userName, pUserB->userName)) {
			if (pUserB == pSystemUserHead && pUserB->next == NULL) {    //���ϵͳֻ��һ����Ʒ��Ϣ
				free(pSystemUserHead);
				pSystemUserHead = NULL;
				printf("�û���Ϣɾ���ɹ�!\n");
				return;
			}
			pUserA->next = pUserB->next;
			if (pSystemUserHead == pUserB)
				pSystemUserHead = pUserB->next;
			free(pUserB);
			printf("�û���Ϣɾ���ɹ���\n");
			return;
		}
		else {
			pUserA = pUserB;
			pUserB = pUserB->next;
		}
	}
	printf("�Բ��𣬲����ڸ��ʺŵ��û���Ϣ!");
}
//�û���Ϣ����:���,�޸�,ɾ��,��ѯ//
void UserManage() {                 //�û���Ϣ����//
	int select;
	//����Ա��ʾģ��//
	while (1) {
		printf("�װ��Ĺ���Ա%sͬ־,��Ŀǰ��������û���Ϣ������:\n", currentUser);
		printf("  (1)�û���Ϣ�鿴\n");
		printf("  (2)�û���Ϣ���\n");
		printf("  (3)�û���Ϣ�޸�\n");
		printf("  (4)�û���Ϣɾ��\n");
		printf("  (5)�����ϼ��˵�\n");
		printf("  (6)�˳���½ϵͳ\n");
		printf("���������湦�ܶ�Ӧ����Ž��й���ѡ��:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			UserInfoView();     //�����û���Ϣ�鿴�ĺ���//
			continue;
		case 2:
			UserInfoAdd();       //�����û���Ϣ��Ӻ���//
			continue;
		case 3:
			UserInfoModify();    //�����û���Ϣ�޸ĺ���//
			continue;
		case 4:
			UserInfoDelete();    //�����û���Ϣɾ������//
			continue;
		case 5:
			AdminOperationMenu();  //�����ϼ�ϵͳ//
			break;
		case 6:
			ExitSystem();        //�˳���½//
			break;
		default:
			break;
		}
	}
}

//��Ʒ�Ĳ鿴����//
void ProductsView() {
	Products *tmpProduct;
	int i;
	i = 1;
	tmpProduct = pProductHead;
	if (NULL == tmpProduct)
		printf("�Բ���,Ŀǰ��û����Ʒ��Ϣ");
	else {
		while (NULL != tmpProduct) {
			printf("��%d����Ʒ��Ϣ����:\n", i);
			printf("��Ʒ���: %d\n", tmpProduct->productId);
			printf("��Ʒ����: %s\n", tmpProduct->productName);
			printf("��Ʒ�ͺ�: %s\n", tmpProduct->productType);
			printf("��Ʒ����: %s\n", tmpProduct->productCompany);
			printf("��Ʒ�۸�: %f\n", tmpProduct->productPrice);
			printf("��Ʒ����: %d\n", tmpProduct->productCount);
			printf("��Ʒ������Ϣ: %s\n", tmpProduct->memo);

			tmpProduct = tmpProduct->next;
			i++;
		}
	}
}
//��Ʒ���Һ���//
void ProductFind() {
	Products *tmpProduct;
	int findWay, productId;
	char productName[20];
	printf("�װ���%s����,���,�����ڽ������Ʒ��ѯ����:\n", currentUser);
	printf("��ѡ���ѯ��ʽ: 1--����Ʒ��Ų�ѯ  2--����Ʒ���Ʋ�ѯ\n");
	scanf("%d", &findWay);
	tmpProduct = pProductHead;
	switch (findWay) {
	case 1:
		printf("�������ѯ����Ʒ���:");
		scanf("%d", &productId);
		while (NULL != tmpProduct) {
			if (productId == tmpProduct->productId) {
				printf("���ѯ����Ʒ���Ϊ%d����Ʒ��Ϣ����:\n", productId);
				printf("  ��Ʒ����: %s\n", tmpProduct->productName);
				printf("  ��Ʒ�ͺ�: %s\n", tmpProduct->productType);
				printf("  ��Ʒ����: %s\n", tmpProduct->productCompany);
				printf("  ��Ʒ�۸�: %f\n", tmpProduct->productPrice);
				printf("  ��Ʒ����: %d\n", tmpProduct->productCount);
				printf("  ��Ʒ������Ϣ: %s\n", tmpProduct->memo);
				return;
			}
			tmpProduct = tmpProduct->next;
		}
		printf("�Բ���,�����ڸ���Ʒ��ŵ���Ʒ!\n");
		break;
	case 2:
		printf("�������ѯ����Ʒ����:");
		scanf("%s", productName);
		while (NULL != tmpProduct) {
			if (0 == strcmp(tmpProduct->productName, productName)) {
				printf("��Ҫ��ѯ����Ʒ����Ϊ%s����Ʒ��Ϣ����:\n", productName);
				printf("  ��Ʒ����: %s\n", tmpProduct->productName);
				printf("  ��Ʒ�ͺ�: %s\n", tmpProduct->productType);
				printf("  ��Ʒ����: %s\n", tmpProduct->productCompany);
				printf("  ��Ʒ�۸�: %f\n", tmpProduct->productPrice);
				printf("  ��Ʒ����: %d\n", tmpProduct->productCount);
				printf("  ��Ʒ������Ϣ: %s\n", tmpProduct->memo);
				return;
			}
			tmpProduct = tmpProduct->next;
		}
		printf("�Բ���,�����ڸ���Ʒ��ŵ���Ʒ!\n");
		break;
	default:
		break;
	}
}
//��Ʒ��Ӻ���//
void InputAndAddProduct() {
	Products product;
	printf("�װ���%s����,���,��������������Ʒ����Ϣ:\n", currentUser);
	printf("��Ʒ����:");
	scanf("%s", product.productName);
	printf("��Ʒ�ͺ�:");
	scanf("%s", product.productType);
	printf("��Ʒ������:");
	scanf("%s", product.productCompany);
	printf("��Ʒ�۸�:");
	scanf("%f", &product.productPrice);
	printf("��Ʒ����:");
	scanf("%d", &product.productCount);
	printf("��Ʒ������Ϣ:");
	scanf("%s", product.memo);
	product.next = NULL;

	if (FUNCTION_SUCCESS == AddProduct(&product))
		printf("��Ʒ��Ϣ��ӳɹ�!\n");
}
//��Ʒ�޸ĺ���//
void ModifyProduct() {
	int productId;                                //���޸ĵ���Ʒ���
	Products *tmpProduct;
	printf("�װ���%s����,���,�����ڽ������Ʒ��Ϣ�޸Ĺ���:\n", currentUser);
	printf("������Ҫ�޸ĵ���Ʒ���:");
	scanf("%d", &productId);
	tmpProduct = pProductHead;
	if (NULL == tmpProduct) return;
	while (NULL != tmpProduct) {
		if (productId == tmpProduct->productId) {
			printf("��Ʒ���%d����Ʒ��Ϣ����:\n", productId);
			printf("  ��Ʒ����: %s\n", tmpProduct->productName);
			printf("  ��Ʒ�ͺ�: %s\n", tmpProduct->productType);
			printf("  ��Ʒ����: %s\n", tmpProduct->productCompany);
			printf("  ��Ʒ�۸�: %f\n", tmpProduct->productPrice);
			printf("  ��Ʒ����: %d\n", tmpProduct->productCount);
			printf("  ��Ʒ������Ϣ: %s\n", tmpProduct->memo);

			printf("����������޸ĸ���Ʒ����Ӧ��Ϣ:\n");
			printf("�µ���Ʒ����: ");
			scanf("%s", tmpProduct->productName);
			printf("�µ���Ʒ�ͺ�: ");
			scanf("%s", tmpProduct->productType);
			printf("�µ���Ʒ����: ");
			scanf("%s", tmpProduct->productCompany);
			printf("�µ���Ʒ�۸�: ");
			scanf("%f", &tmpProduct->productPrice);
			printf("�µ���Ʒ����: ");
			scanf("%d", &tmpProduct->productCount);
			printf("�µ���Ʒ������Ϣ: ");
			scanf("%s", tmpProduct->memo);

			printf("��Ʒ��Ϣ�޸ĳɹ�!\n");

			break;
		}
		tmpProduct = tmpProduct->next;
	}
}
//��Ʒɾ������//
void DeleteProduct() {
	int productId = 0;
	Products *tmpProductA, *tmpProductB;
	printf("�װ���%s����,���,�����ڽ������Ʒɾ������:\n", currentUser);
	printf("��������Ҫɾ������Ʒ���:\n");
	scanf("%d", &productId);
	tmpProductA = tmpProductB = pProductHead;    //tmpProductBָ��Ҫɾ���ļ�¼��tmpProductAָ��ǰһ����¼
	if (NULL == tmpProductB) return;
	while (NULL != tmpProductB) {
		if (tmpProductB->productId == productId) {
			if (tmpProductB == pProductHead && tmpProductB->next == NULL) { //���ϵͳֻ��һ����Ʒ��Ϣ
				free(pProductHead);
				pProductHead = NULL;
				printf("��Ʒ��Ϣɾ���ɹ�!\n");
				return;
			}
			tmpProductA->next = tmpProductB->next;
			if (pProductHead == tmpProductB)
				pProductHead = tmpProductB->next;
			free(tmpProductB);
			printf("��Ʒ��Ϣɾ���ɹ���\n");
			return;
		}
		else {
			tmpProductA = tmpProductB;
			tmpProductB = tmpProductB->next;
		}
	}
	printf("�Բ��𣬲����ڸ���Ʒ��ŵ���Ϣ!");
}

//��Ʒ����ģ��//
void ProductsManage() {
	int select;
	while (1) {
		printf("�װ���%s����,���,�����ڽ��������Ʒ������,�����ѡ�����¹���:\n", currentUser);
		printf("   (1)��Ʒ��Ϣ�鿴\n");
		printf("   (2)��Ʒ��Ϣ����\n");
		printf("   (3)��Ʒ��Ϣ���\n");
		printf("   (4)��Ʒ��Ϣ�޸�\n");
		printf("   (5)��Ʒ��Ϣɾ��\n");
		printf("   (6)������һ���˵�\n");
		printf("   (7)�˳���½ϵͳ\n");
		printf("��ѡ��Ӧ�Ĳ������:");
		scanf("%d", &select);
		switch (select) {
		case 1:
			ProductsView();   //������Ʒ�鿴����//
			continue;
		case 2:
			ProductFind();    //������Ʒ��Ϣ���Һ���//
			continue;
		case 3:
			InputAndAddProduct();  //������Ʒ��Ӻ���//
			continue;
		case 4:
			ModifyProduct();     //������Ʒ�޸ĺ���//
			continue;
		case 5:
			DeleteProduct();   //����ɾ����Ʒ��Ϣ����//
			continue;
		case 6:
			switch (currentUserType) {   //������һ��//
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

//����Ա��ӭ���溯��
void AdminOperationMenu() {
	int select;
	while (1) {
		printf("�װ��Ĺ���Ա%sͬ־,��ӭʹ�ñ�ϵͳ,��ӵ���������й���:\n", currentUser);
		printf("  (1)���������޸�\n");
		printf("  (2)�û���Ϣ����:���,�޸�,��ѯ,ɾ��\n");
		printf("  (3)��Ʒ��Ϣ����:���,�޸�,��ѯ,ɾ��\n");
		printf("  (4)�˳�ϵͳ\n");
		printf("���������湦�ܶ�Ӧ����Ž��й���ѡ��:");
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

//�����ۺ�����ͳ��//
void ShowDaySellReport() {
	int year, month, day;
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("���%s:��ǰ���ܽ����������۱�����ʾ\n", currentUser);
	printf("����������ʱ�����:");
	scanf("%d", &year);
	printf("����������ʱ���·�:");
	scanf("%d", &month);
	printf("����������ʱ�����:");
	scanf("%d", &day);

	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		if (year == tmpSellInfo->year &&
			month == tmpSellInfo->month &&
			day == tmpSellInfo->day &&
			((SELL_USER_TYPE == currentUserType) ? (0 == strcmp(tmpSellInfo->userName, currentUser)) : 1)) {
			rsCount++;
			printf("���������ĵ�%d����Ʒ���ۼ�¼��Ϣ����:\n", rsCount);
			printf(" ���۱��:%d\n", tmpSellInfo->saleId);
			printf(" ��Ʒ���:%d\n", tmpSellInfo->productId);
			getProductNameById(tmpSellInfo->productId, productName);
			printf(" ��Ʒ����:%s\n", productName);
			onePrice = getPriceById(tmpSellInfo->productId);
			printf(" ��Ʒ����:%f\n", onePrice);
			printf(" ��������:%d\n", tmpSellInfo->sellCount);
			printf(" ����Ա:%s\n", tmpSellInfo->userName);
			printf(" ����ʱ��:%d��%d��%d��\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
			totalPrice += onePrice * tmpSellInfo->sellCount;
		}
		tmpSellInfo = tmpSellInfo->next;
	}
	printf("�ܹ���%d�����������ļ�¼,�����ܼ�%fԪ\n", rsCount, totalPrice);
}
//������������ͳ��//
void ShowMonthSellReport() {
	int year, month;
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("���%s:��ǰ���ܽ����������۱�����ʾ\n", currentUser);
	printf("����������ʱ�����:");
	scanf("%d", &year);
	printf("����������ʱ���·�:");
	scanf("%d", &month);

	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		if (year == tmpSellInfo->year &&
			month == tmpSellInfo->month &&
			((SELL_USER_TYPE == currentUserType) ? (0 == strcmp(tmpSellInfo->userName, currentUser)) : 1)) {
			rsCount++;
			printf("���������ĵ�%d����Ʒ���ۼ�¼��Ϣ����:\n", rsCount);
			printf(" ���۱��:%d\n", tmpSellInfo->saleId);
			printf(" ��Ʒ���:%d\n", tmpSellInfo->productId);
			getProductNameById(tmpSellInfo->productId, productName);
			printf(" ��Ʒ����:%s\n", productName);
			onePrice = getPriceById(tmpSellInfo->productId);
			printf(" ��Ʒ����:%f\n", onePrice);
			printf(" ��������:%d\n", tmpSellInfo->sellCount);
			printf(" ����Ա:%s\n", tmpSellInfo->userName);
			printf(" ����ʱ��:%d��%d��%d��\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
			totalPrice += onePrice * tmpSellInfo->sellCount;
		}
		tmpSellInfo = tmpSellInfo->next;
	}
	printf("�ܹ���%d�����������ļ�¼,�����ܼ�%fԪ\n", rsCount, totalPrice);
}
//��ʾ����Ա��ҵ��//
void ShowEmployeeSellReport() {
	char userName[20];
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("���%s:��ǰ���ܽ���������Ա���۱�����ʾ\n", currentUser);
	printf("����������Ա���ʻ���:");
	scanf("%s", userName);
	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		if (0 == strcmp(userName, tmpSellInfo->userName)) {
			rsCount++;
			printf("���������ĵ�%d����Ʒ���ۼ�¼��Ϣ����:\n", rsCount);
			printf(" ���۱��:%d\n", tmpSellInfo->saleId);
			printf(" ��Ʒ���:%d\n", tmpSellInfo->productId);
			getProductNameById(tmpSellInfo->productId, productName);
			printf(" ��Ʒ����:%s\n", productName);
			onePrice = getPriceById(tmpSellInfo->productId);
			printf(" ��Ʒ����:%f\n", onePrice);
			printf(" ��������:%d\n", tmpSellInfo->sellCount);
			printf(" ����Ա:%s\n", tmpSellInfo->userName);
			printf(" ����ʱ��:%d��%d��%d��\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
			totalPrice += onePrice * tmpSellInfo->sellCount;
		}
		tmpSellInfo = tmpSellInfo->next;
	}
	printf("�ܹ���%d�����������ļ�¼,�����ܼ�%fԪ\n", rsCount, totalPrice);
}
//��ʾ��������Ա��ҵ��//
void ShowAllSellReport() {
	int rsCount = 0;
	float totalPrice = 0.0, onePrice;
	char productName[20];
	SellInfoRecord *tmpSellInfo;
	printf("���%s:��ǰ���ܽ������������۱�����ʾ\n", currentUser);
	tmpSellInfo = pSellInfoHead;
	if (NULL == tmpSellInfo) return;
	while (NULL != tmpSellInfo) {
		rsCount++;
		printf("��%d����Ʒ���ۼ�¼��Ϣ����:\n", rsCount);
		printf(" ���۱��:%d\n", tmpSellInfo->saleId);
		printf(" ��Ʒ���:%d\n", tmpSellInfo->productId);
		getProductNameById(tmpSellInfo->productId, productName);
		printf(" ��Ʒ����:%s\n", productName);
		onePrice = getPriceById(tmpSellInfo->productId);
		printf(" ��Ʒ����:%f\n", onePrice);
		printf(" ��������:%d\n", tmpSellInfo->sellCount);
		printf(" ����Ա:%s\n", tmpSellInfo->userName);
		printf(" ����ʱ��:%d��%d��%d��\n", tmpSellInfo->year, tmpSellInfo->month, tmpSellInfo->day);
		totalPrice += onePrice * tmpSellInfo->sellCount;

		tmpSellInfo = tmpSellInfo->next;
	}
	printf("�ܹ���%d�����������ļ�¼,�����ܼ�%fԪ\n", rsCount, totalPrice);
}
//���۱�����ʾ//
void ReportPrint() {
	int select = 0;
	if (SELL_USER_TYPE != currentUserType) {
		while (1) {
			printf("�װ�������%s,��ã������ڽ���������۱����ܽ���:\n", currentUser);
			printf("  (1)������Ʒ�������\n");
			printf("  (2)��Ʒ�����۱���\n");
			printf("  (3)��Ʒ�����۱���\n");
			printf("  (4)����Ա���۱���\n");
			printf("  (5)�����ϼ��˵�\n");
			printf("  (6)�˳���½ϵͳ\n");
			printf("��ѡ���Ӧ�Ĺ��ܺ�:");
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
			printf("�װ�������Ա%s,��ã������ڽ���������۱����ܽ���:\n", currentUser);
			printf("  (1)�鿴�Լ������۱���\n");
			printf("  (2)�鿴�Լ������۱���\n");
			printf("  (3)�����ϼ��˵�\n");
			printf("  (4)�˳���½ϵͳ");
			printf("��ѡ����Ӧ�Ĺ��ܺ�:");
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

//�곤��ӭ����//
void BossOperationMenu() {
	int select;
	while (1) {
		printf("�װ��ĵ곤%sͬ־,��ӭʹ�ñ�ϵͳ,��ӵ���������й���:\n", currentUser);
		printf("  (1)���������޸�\n");
		printf("  (2)��Ʒ��Ϣ����:���,�޸�,��ѯ,ɾ��\n");
		printf("  (3)���۱�����ʾ:�ձ���,�±���,��Ʒ����������,����Աҵ������\n");
		printf("  (4)�˳�ϵͳ\n");
		printf("���������湦�ܶ�Ӧ����Ž��й���ѡ��:");
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

//����Ա����ģ��//
void SellOperationMenu() {
	int select;
	while (1) {
		printf("�װ�������Ա%sͬ־,��ӭʹ�ñ�ϵͳ,��ӵ���������й���:\n", currentUser);
		printf("  (1)��Ʒ���\n");
		printf("  (2)��Ʒ��ѯ\n");
		printf("  (3)��Ʒ����\n");
		printf("  (4)����鿴\n");
		printf("  (5)�˳���½ϵͳ\n");
		printf("���������湦�ܶ�Ӧ����Ž��й���ѡ��:");
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
