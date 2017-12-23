//template_scan_element_type.h ����ͷ�ļ�

#ifndef _TEMPLATE_SCAN_ELEMENT_TYPE_H_
#define _TEMPLATE_SCAN_ELEMENT_TYPE_H_


#if defined(__cplusplus)
extern "C" {
#endif

#pragma pack(push)
#pragma pack(1)



	//��ͼ��������Ӧ�ı�ʶ��
	//2 * 5 = 10
	typedef struct _Coords {

		unsigned short MapID;
		unsigned short TopX;
		unsigned short TopY;
		unsigned short DownX;
		unsigned short DownY;

	}Coords;


	typedef Coords CoordsArray[50];			//��������

											//��������ݽṹ    SCAN --> UI 
											//�ýṹ�Ĵ�С: 128 + 400 + 500 + 1 + 1 + 500 = 1530 �ֽ�
	typedef struct _templateScanElement {

		char identifyID[128];					//��ʶ��ID
		char objectAnswer[400];					//�͹����. Ԥ����С����: ÿ����5���ֽ�,��װ80��.  ��ʽΪ:  A~BC~AB~ABCD~C~;  C�ַ������,��\0��β
		unsigned char totalNumberPaper;			//�Ծ��ܷ���
		char toalPaperName[10][50];				//�����Ծ����ļ���		500
		unsigned char subMapCoordNum;			//������ͼ����
		CoordsArray  coordsDataToUi;			//�����Ծ�,������������ͼ����㼯��

	}templateScanElement;


	//�ϴ�����������ʽ  Net --> SERVER
	// 1 + 128 + 2 + 400 + 1 + 1 + 50 *10 = 1033
	typedef struct _SendServerExFrame {

		unsigned char IDLen;					// ���� ID�ĳ���; 
		char ID[128];							// ����������Ϊ ASCII��,
		unsigned short objectLenth;				// �͹���𰸳��� 
		char objectAnswer[400];					// �͹����, ��ʽ A~AB~D��	
		unsigned char totalNumber;				// �����Ծ���ɨ��ͼƬ����
		unsigned char  subMapCoordNum;			// ��������ͼ����;
		CoordsArray coordsValSet;				// �����Ծ�������ͼ����㼯��; Coords[50]	 	n : ��ͼ����

	}SendServerExFrame;


#if 1		

	//UI ---> net ����Ϣ, Ӧ�ð����ļ���·��; ���Խṹ�� 
	typedef struct {

		char fileDir[256];					//�ļ����ڵ�Ŀ¼
		templateScanElement sendData;		//��չ��Ϣ

	}UitoNetExFrame;


	//1+1+256 = 258;
	typedef struct _option_content_
	{
		unsigned char 	optionID;
		unsigned char 	optionNameLenth;
		char 			optionName[256];

	}optionContent;
	typedef  optionContent optionArray[10];

	//1+1+256+1+258*10 = 2839
	typedef struct _project_content_
	{
		unsigned char 	projectID;
		unsigned char 	projectNameLenth;
		char 			projectName[256];
		unsigned char 	optionNum;
		optionArray 	optionSet;
	}projectContent;
	typedef projectContent  projectArray[10];

	//1+2839*10 = 28391 == 28K	  Net ---> UI (client request's reply data from server )
	typedef struct _client_request_content_
	{
		unsigned char 	projectNum;
		projectArray  	projectSet;
	}clientRequestContent;



	//1+1 = 2
	typedef struct _select_content_
	{
		unsigned char projectID;
		unsigned char optionID;

	}selectContent;
	typedef selectContent  requestContent[10];

	//1+2*10 = 21		UI --->  Net ---> server (The downLoad template request news)
	typedef struct _downLoad_template_request_
	{
		unsigned char   projectNum;
		requestContent  conData;

	}downLoadTemplateRequest;




#endif

#pragma pack(pop)

#if defined(__cplusplus)
}
#endif


#endif
