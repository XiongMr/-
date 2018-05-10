#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

struct DATA {
	char name[20], sex[10], major[20], eduStatus[20];
	int age;
	struct DATA *next;
};

typedef struct DATA data;

data * readFile(data *);	//��ȡ�ļ��е���Ϣ
void displayItem(int);		//չʾѡ�����
data *count(data *);		//ͳ�ƹ��� 
data *displayAll(data *);	//չʾ�����Ա
int HowManyPeople(data *);	//�ж��������ж����� 
data *creatNew(data *);		//�����Ϣ���� 
data *creatLink(data *);	//��������
data *addPeople(data *);	//��ԭ��������ӳ�Ա 
data *deleteAll(data *);	//ɾ��������Ϣ 
void writeAddFile(data *);	//����д���µ�����
data *delAStruct(data *, data *);//ɾ���������һ���ڵ�
void revise(data *);		//�޸��������һ���ڵ�
data *search(data *, char *);	//�������в���������ͬ�Ľṹ��
void delFunction(data *);		//ɾ����Ϣ���ܵĺ��� 
void writeFileAll(data *);		//�����������������д���ļ� 

int main() {
	int choice;
	data *head, *p;
	char hisName[20];
	
	head = (data *)malloc(sizeof(data));
	head -> next = NULL;
	
	head = readFile(head);	//�������ȶ�ȡ������ļ�
	
	displayItem(HowManyPeople(head));	//չʾѡ�����
	
	while (scanf("%d", &choice)) {      //��scanf�ɹ����յ�һ�����ֵ�ʱ��᷵��һ����ֵ������while����������������յ��������򷵻�0���Ͳ�����������ֱ���˳�
		system("cls");					//�������������ֽ������� 
		
		switch (choice) {               //�ж��û������������
			case 1:
				getchar();
				head = creatNew(head);  //����creatNew���������������� �� ���һ���ڵ�
				break;
			case 2:
				delFunction(head);      //����delFunction������ɾ���������� �� ɾ��������ָ���ڵ�
				break;
			case 3:
				getchar(); 
				revise(head);           //����revise�������޸�ĳ����Ա
				break;
			case 4:
				head = displayAll(head);//����displayAll������չʾ��������������
				break;
			case 5:
				printf("���������ѯ�ĳ�Ա���֣�\n");
				getchar();              //������1~7ѡ���ʱ�򣬻�����һ���س���������س������������gets��ȡ�ַ�����������Ҫ��getchar()�����ѻس����Ե�
				gets(hisName);
				p = search(head, hisName);//p���ص��ǲ�ѯ�����Ǹ������ڵĽڵ��ָ�룬�������NULL˵��û�ҵ�
				if (p == NULL)
					printf("û������ˣ�");
				else 
					printf("������%s\t�Ա�%s\t���䣺%d\tרҵ��%s\t�Ļ��̶ȣ�%s\n",
				 			p -> name, p -> sex, p -> age, p -> major, p -> eduStatus);
				break;
			case 6:
				head = count(head);     //����count������ͳ�Ʒ���Ҫ��ĳ�Ա
				break;
			case 7:
				printf("���ڸ������ݣ����Եȡ�");
				writeFileAll(head);     //����writeFileAll���������½������е�����д���ļ�
				system("cls");          //����
				printf("ллʹ�ã��ټ���");
				sleep(3);               //��ʱ����������������ʱ����
				return 0;
		}
		
		displayItem(HowManyPeople(head));//չʾ�������
	}
	
	return 0;
}

/*************************************
 *���ܣ�չʾ������Ŀ���б���������� *
 *���룺�������� 					 *
 *���أ��� 							 *
 *************************************
 */
void displayItem(int sum) {
	printf("\n\n");
	printf("******************************\n");
	printf("***��ӭ�������˼���¼�����***\n");
	printf("******���ڹ���%d�˵���Ϣ******\n", sum);
	printf("******************************\n");
	printf("** ����1�������Ϣ\n");
	printf("** ����2��ɾ����Ϣ\n");
	printf("** ����3���޸���Ϣ\n");
	printf("** ����4��չʾȫ����Ϣ\n");
	printf("** ����5����ѯ������Ϣ\n");
	printf("** ����6��ʹ��ͳ�ƹ���\n");
	printf("** ����7���˳�����\n");
	printf("******************************\n");
}

/***************************
 *���ܣ��б��������Ϣ���� *
 *���룺Ҫд�������ͷָ�� *
 *���أ������ͷָ�� 	   *
 ***************************
 */
data *creatNew(data *head){
	
	int choice;
	
	printf("** ����1����ԭ�г�Ա������³�Ա\n");
	printf("** ����2��ɾ��ԭ�г�Ա����������Ϣ\n"); 
	scanf("%d", &choice);
	getchar();                          //����������ֺ���Ļس����Ե�
	
	switch(choice) {                    //ͨ���û���������������ò�ͬ�ĺ���
		case 1:
			head = addPeople(head);     //����addPeople������ԭ�еĻ�������ӳ�Ա
			break;
		case 2:
			head = deleteAll(head);     //ɾ����������
			head = creatLink(head);     //����creatLink�����������µ�����
			break;
	}
	
	return head;
}

/***************************
 *���ܣ��б���ɾ����Ϣ���� *
 *���룺Ҫд�������ͷָ�� *
 *���أ���				   *
 ***************************
 */
void delFunction(data *head) {
	printf("** ����1��ɾ��ָ����Ա\n");
	printf("** ����2��ɾ�����г�Ա\n");
	
	int choice;
	char Fname[20];
	data *del;
	scanf("%d", &choice);
	getchar();                          //�Ե��س�
	
	if (choice == 2)
		head = deleteAll(head);         //ɾ����������
	else {
		printf("��������ɾ�������֣�\n");
		gets(Fname);
		del = search(head, Fname); 		//���ҵ�Ҫɾ����Ա��λ�ã���ɾ��
		
		while (del == NULL) {           //���delָ��ָ����һ���յ�λ�ã������������û��Ҫɾ���������Ա
			printf("û���ҵ�����ˣ����������룺\n"); 
			gets(Fname);
			del = search(head, Fname);  //���ò��Һ���
		}
		
		head = delAStruct(head, del);   //����delAStruct������ɾ�������е�һ���ڵ�
	} 
		 
} 

/***************************
 *���ܣ�ɾ���������������� *
 *���룺�����ͷָ�� 	   *
 *���أ������ͷָ�� 	   *
 ***************************
 */
data *deleteAll(data *head) {
	data *p, *q;
	p = head -> next;
	
	while (p != NULL) {
		q = p -> next;					//ָ��q������ʱ���p -> next��Ҳ����p����һ���ڵ㣩����Ϊfree(p)���p�ͷŵ����ͷ��Ժ�p -> next���Ҳ�����
		free(p);
		p = q;
	}
	
	remove("datas.myC");                //remove������������ɾ�������е�ĳ���ļ�����stdio.h���ͷ�ļ��У�����Ĳ������ļ���·��
	head -> next = NULL;
	
	return head;
}

/*************************
 *���ܣ�����һ���µ����� *
 *���룺�����ͷָ�� 	 *
 *���أ������ͷָ�� 	 *
 *************************
 */
data *creatLink(data *head) {
	data *p, *q;
	q = head;
	p = (data *) malloc(sizeof(data)); 
	
	
	printf("������������(�����Ӣ�Ľ���)\n"); 
	gets(p -> name);
	while ((*p -> name >= 'a' && *p -> name <= 'z')       //*p -> name�У�p -> name��������ַ�����ָ�룬��ǰ�����һ��*����ȡֵ��ȡ�����ַ������һ����Ա��ֵ
		|| (*p -> name >= 'A' && *p -> name <= 'A')) {
		if (search(head, p -> name)){                   //����search������ѯ������������ͬ�Ľڵ㣬���û���ҵ���search�����᷵��NULL����ʱ��if���������
			printf("������ͬ������������������������(�����Ӣ�Ľ���)\n");
			gets(p -> name);
			continue;
		}

		printf("��������/�����Ա�\n");                //������������Ҫ��д������
		gets(p -> sex);
		printf("��������/�������䣺\n");
		scanf("%d", &p -> age);
		getchar();
		printf("��������/����רҵ��\n");
		gets(p -> major);
		printf("��������/�����Ļ��̶ȣ�\n");
		gets(p -> eduStatus);
		
		q -> next = p;                                  //��������
		q = p;
		p -> next = NULL;
		p = (data *) malloc(sizeof(data));              //����һ���µ��ڴ�
		printf("������������(�����Ӣ�Ľ���)\n"); 
		gets(p -> name);
	}
	
	free(p);                                            //����û������˷�Ӣ�ģ��������������������������¿ռ䲻��Ҫ¼������Ϣ������Ͱ���鲻��Ҫ�õĿռ��ͷŵ���
	q -> next = NULL;                                   //������β��ΪNULL
	
	writeFileAll(head);                                 //����writeFileAll�����������������������д���ļ�
	
	return head;
}

/*********************************
 *���ܣ����������������һ����Ա *
 *���룺�����ͷָ�� 			 *
 *���أ������ͷָ�� 			 *
 *********************************
 */
data *addPeople(data * head) {
	data *p, *q;
	
	q = head -> next;
	p = (data *) malloc(sizeof(data)); 
	
	printf("������������(�����Ӣ�Ľ���)\n"); 			//�������һ�κ������creatLink()��������һ�����в����Ŀ��Բ��������ע��
	gets(p -> name);
	while ((*p -> name >= 'a' && *p -> name <= 'z') 
		|| (*p -> name >= 'A' && *p -> name <= 'Z')) {

		if (search(head, p -> name)){
			printf("������ͬ������������������������(�����Ӣ�Ľ���)\n");
			gets(p -> name);
			continue;
		}
		
		printf("��������/�����Ա�\n");
		gets(p -> sex);
		printf("��������/�������䣺\n");
		scanf("%d", &p -> age);
		getchar();
		printf("��������/����רҵ��\n");
		gets(p -> major);
		printf("��������/�����Ļ��̶ȣ�\n");
		gets(p -> eduStatus);
		
		head -> next = p;
		p -> next = q;									//�������ͷ���룬�����Ǵ�����β���롣�������ͷ��������˼����������������һЩ
		
		writeAddFile(p);								//�����ǰ��µ�����д���ļ���ĩβ����ֹ���ݶ�ʧ
		
		q = p;
		p = (data *) malloc(sizeof(data)); 
		printf("������������(�����Ӣ�Ľ���)\n"); 
		gets(p -> name);
	}
	
	free(p);
	
	return head;
}

/*************************
 *���ܣ�ͳ�������е����� *
 *���룺�����ͷָ�� 	 *
 *���أ������е����� 	 *
 *************************
 */
int HowManyPeople(data *head) {
	data *p;
	int sum = 0;
	
	for (p = head -> next; p != NULL; p = p -> next)	//ÿ��һ����������+1��ÿ���������һ���˵���Ϣ 
		sum++;
		
	return sum;
}

/*********************************
 *���ܣ�������������г�Ա����Ϣ *
 *���룺�����ͷָ�� 			 *
 *���أ������ͷָ�� 			 *
 *********************************
 */
data *displayAll(data *head) {
	data *p;
	p = head -> next;
	
	while (p != NULL) {
		printf("������%s\t�Ա�%s\t���䣺%d\tרҵ��%s\t�Ļ��̶ȣ�%s\n",
				 p -> name, p -> sex, p -> age, p -> major, p -> eduStatus);
		p = p -> next;
	}
	
	return head;
}

/*********************
 *���ܣ�ͳ�ƹ��� 	 *
 *���룺�����ͷָ�� *
 *���أ������ͷָ�� *
 *********************
 */
data *count(data *head) {
	int choice, Fage, a[5] = {0};				//a[5]����4��ѡ�1Ϊ��Ҫɸѡ��0Ϊ����Ҫɸѡ
	char Fsex[20], Fmajor[50], FeduStatus[50];
	
	/*����ɸѡ��Ŀ*/	
	while (1) {
		printf("\n\n");
		printf("************************\n");
		printf("** ����1�������������ֵ\n");
		printf("** ����2�������Ա�\n");
		printf("** ����3������רҵ\n");
		printf("** ����4�������Ļ��̶�\n");
		printf("** ����5����ʼ\n");
		printf("** ����6��ȡ��\n");
		printf("************************\n");
		scanf("%d", &choice);

		switch(choice) {                        //�ж��û���ѡ��
			case 1:
				printf("��������������:\n");
				scanf("%d", &Fage);
				a[1] = 1;
				printf("���óɹ���\n");
				break;
			case 2:
				printf("������Ҫ����Ա�:\n");
				getchar();						//�����getchar()��Ϊ�˳Ե���������ʱ�Ļس���
				gets(Fsex);
				a[2] = 1;
				printf("���óɹ���\n");
				break;
			case 3:
				printf("������Ҫ���רҵ:\n");
				getchar();
				gets(Fmajor);
				a[3] = 1;
				printf("���óɹ���\n");
				break;
			case 4:
				printf("������Ҫ����Ļ��̶�:\n");
				getchar();
				gets(FeduStatus);
				a[4] = 1;
				printf("���óɹ���\n");
				break;
			case 5:
				break;
			case 6:
				return head;
		}
		
		if(choice == 5)
			break;
	}
	
	
	/*��ʼɸѡ*/
	printf("\n\n");
	int i, key, sum = 0;						//key�ĳ�ʼֵΪ1����������ɸѡ�������������һ���������������޸ĳ�0.
	data *p; 
	
	p = head -> next;
	
	while (p != NULL) {                         //ɸѡ��ԭ���ǣ���������������ÿ����Ա�������ж�a[1~5]������a�����Ƿ���Ҫɸѡ��������Ҫɸѡ���ж��Ƿ���������������������Ҫɸѡ������
		key = 1;
		for (i = 1; i <= 4 && key == 1; i++){
			if (a[i] != 1)
				continue;
			else {
				switch (i) {                    //i ��� 1�ӵ� 4�������ѭ�� 4�Σ����ж��Ƿ���Ҫɸѡ
					case 1:
						if (p -> age >= Fage)
							key = 0;
						break;
					case 2:
						if (strcmp(p -> sex, Fsex))	//strcmp�е�����ָ��ָ����ַ��������ͬ���򷵻� 0.��ִ��if�е����
							key = 0;
						break;
					case 3:
						if (strcmp(p -> major, Fmajor))
							key = 0;
						break;
					case 4:
						if (strcmp(p -> eduStatus, FeduStatus))
							key = 0;
						break;
				}
			}
		}
		if (key == 1){
			printf("������%s\t�Ա�%s\t���䣺%d\tרҵ��%s\t�Ļ��̶ȣ�%s\n",
				 p -> name, p -> sex, p -> age, p -> major, p -> eduStatus);
			sum++;                                  //sum����ͳ����������������
		}
		else
			key = 1;
		
		p = p -> next;
	}
	
	printf("���������Ĺ���%d�ˡ�\n", sum);
	
	return head; 
}

/*************************
 *���ܣ���ȡ�ļ��е���Ϣ *
 *���룺�����ͷָ�� 	 *
 *���أ������ͷָ�� 	 *
 *************************
 */
data * readFile(data *head) { 
	FILE * fp;
	data *p, *last;

	last = head;

	if ((fp = fopen("datas.myC", "r")) == NULL) {   //r ����ֻ���ķ�ʽ��
		head -> next = NULL;
		return head;
	}
	else {
		while (!feof(fp)) {                         //�ж�fpָ���Ƿ�ָ�����ļ���ĩβ
			p = (data *) malloc(sizeof(data));
			last->next = p;
			fscanf(fp, "%s%s%d%s%s\n", p->name, p->sex, &p ->age, p->major, p->eduStatus);
			last = p;
		}
		last->next = NULL;
	}

	if (fclose(fp) != 0) {
		printf("Cannot close ""datas.myC!""");
		exit(0);
	}

	return head;
}

/*******************************
 *���ܣ����ļ���ĩβд�������� *
 *���룺Ҫд�����������ָ��   *
 *���أ���					   *
 *******************************
 */
void writeAddFile(data *p) {
	FILE *fp;

	if ((fp = fopen("datas.myC", "a+")) == NULL) {      //a+ �Ƕ���д�ķ�ʽ�򿪣������ԭ�е��ļ�
		printf("д��ʧ�ܣ�");
		exit(0); 
	}

	fseek(fp, 0, SEEK_END);								//��ָ��ָ���ļ���ĩβ

	fprintf(fp,"%s %s %d %s %s\n", p -> name, p -> sex, p ->age, p -> major, p -> eduStatus);

	if (fclose(fp) != 0) {
		printf("Cannot close the file !");
		exit(0);
	}

}

/***********************************
 *���ܣ������������������д���ļ� *
 *���룺Ҫд�����������ָ��	   *
 *���أ���						   *
 ***********************************
 */
void writeFileAll(data *head) {
	FILE *fp;
	data *p;
	p = head -> next;
	
	if (head -> next == NULL)
		return ;
		
	if ((fp = fopen("datas.myC", "w")) == NULL) {       //w ����ֻ���ķ�ʽ�򿪣��������ԭ�����ļ�
		printf("д��ʧ��");
		exit(0); 
	}
	
	while (p != NULL) {
			fprintf(fp, "%s %s %d %s %s\n", p->name, p->sex, p -> age, p->major, p->eduStatus);
		p = p -> next;
	}
	
	if (fclose(fp) != 0) {
		printf("Cannot close the file !");
		exit(0);
	}
} 

/***************************************
 *���ܣ�ɾ���������һ���ڵ� 		   *
 *���룺1.�����ͷ��2.Ҫɾ��λ�õ�ָ�� *
 *���أ������ͷ 					   *
 ***************************************
 */
data *delAStruct(data *head, data *del ) {
	data *p, *last;
	
	last = head;
	p = head -> next;
	
	for (; p != del; p = p -> next)             //�ҵ�delָ���������е�λ�ã�����lastָ���¼delָ����һ���ڵ��λ��
		last = p;
	
	last -> next = p -> next;                   //ɾ�� p�ڵ㣬���ͷ���
	free(p);
	
	printf("ɾ���ɹ���\n"); 
	return head;
}

/***************************
 *���ܣ��б����޸���Ϣ���� *
 *���룺Ҫд�������ͷָ�� *
 *���أ���				   *
 ***************************
 */
void revise(data *head) {
	int choice;
	char hisname[20];
	data *string;
	
	printf("** ���������޸ĵĳ�Ա������\n");
	gets(hisname);

	string = search(head, hisname);             //����search�������ҽڵ��λ�ã�����ָ��string�������λ��
	if (string == NULL) {                       //���ָ��stringΪ�յĻ���˵��û������ڵ�
		printf("��������û���ҵ������Ա��\n");
		return ;
	}

	printf("** �����޸��ĸ��ط�����\n");
	printf("** ����1���޸�������\n");
	printf("** ����2���޸��Ա�\n");
	printf("** ����3���޸�ְҵ��\n");
	printf("** ����4���޸�ѧ����\n");
	printf("** ����5���޸����䣺\n");
	
	scanf(" %d", &choice);
	getchar(); 
	
	printf("�����������޸ĳɵ����ݣ�\n");
	
	switch (choice) {
		case 1 :
			gets(string -> name);
			break;
		case 2 :
			gets(string -> sex);
			break;
		case 3 :
			gets(string -> major);
			break;
		case 4 :
			gets(string -> eduStatus);
			break;
		case 5:
			scanf("%d", &string -> age);
			break;
	}
	printf("�޸ĳɹ���\n");
}

/*****************************************
 *���ܣ��������в��ҳ�Ա������ͬ�Ľṹ�� *
 *���룺1.�����ͷ��2.Ҫ���ҵ����ֵ�ָ�� *
 *���أ�����ҵ������ض�Ӧ�ṹ���ָ��   *
 *		���û�ҵ�������NULL�� 			 *
 *****************************************
 */
data *search(data *head, char *str) {
	data *p;
	p = head -> next;
	while (p != NULL) {
		if (strcmp(p -> name, str) == 0)
			break;
		else
			p = p -> next;
	}

	return p;
}

