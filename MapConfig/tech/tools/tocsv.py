#coding=gbk
import pandas as pd
import os


gXlsxDirectory = "../strategy/excel"
gCsvDirectory = "csv"

#检查是不是合法
def xlsx_check(filenames):
		print("checkname ="+str(filenames))
		data_xls = pd.read_excel(gXlsxDirectory + "/" + filenames,index_col=0,skiprows=[3], encoding="utf-8")
		#如果index不是int 就报错误
		if data_xls.index[0] != 'int':
				print("ERROR file:["+filenames+"]index is not int")
				return -1
		
		#获取记录数
		allvalues = len(data_xls.index)
		#获取表头名字
		alltitlename = data_xls.columns;
		isok = 0;
		#重复的表头
		ishave=set()
		for f in alltitlename:
				names = f
				if names.find(".1") != -1:
						names = names[0:len(names)-2]
				#print(names)
				test = names[0:7]
				if test == "Unnamed":
						print("ERROR "+filenames+" title name is null["+names+"]")
						isok=1
				if names in ishave:
						print("ERROR "+filenames+" title name duplication["+names+"]")
						isok=1
				else:
						ishave.add(names);
		#重复的主键
		ishave=set()
		for num in range(2,allvalues):
				#print(str(data_xls.index[num]))
				#print(data_xls.index[num] in ishave)
				if data_xls.index[num] in ishave:
						print("ERROR "+filenames+" Primary key duplication["+str(data_xls.index[num])+"]")
						isok=1
				else:
						ishave.add(data_xls.index[num]);
		for f in alltitlename:
				#print(data_xls.iloc[0][f]+":"+data_xls.iloc[1][f])
				if data_xls.iloc[0][f].find('str') == -1:#检测数据
						for num in range(2,allvalues):
								if str(data_xls.iloc[num][f]) == 'nan':
										print("ERROR filename:["+str(filenames)+"] line:["+str(num+3)+"] titlename:["+str(f)+"] type:["+str(data_xls.iloc[0][f])+"] but value is null")
										isok=1
								#print(str(data_xls.index[num])+' '+str(data_xls.iloc[num][f])+' '+data_xls.index.name)
				
		if isok != 0:
				return -1;
		#print(data_xls.columns)#得到表头
		#print(data_xls['Explain'])
		#print(data_xls.iloc[0]['Explain'])#得到表类型
		#print(data_xls.iloc[1]['Explain'])#得到注释的内容
		#获取记录数
		#allvalues = len(data_xls.index)
		#for num in range(2,allvalues):
				#print(str(data_xls.index[num])+' '+data_xls.index[1]+' '+data_xls.index.name)
				#label=data_xls.loc[data_xls.index[num]]
				#print(len(label))
				#print(label)
		#print(data_xls.index[0]+" "+data_xls.index[1]+" "+data_xls.index.name)
		#print(data_xls)
		#label=data_xls.loc[2]
		#print(label)
		#print(label.index[0]+" "+label.index[1]+" "+label.index.name)
		#label=data_xls.iloc[3]
		#print(len(label.index)+" ")
		#data_xls = pd.read_excel(gXlsxDirectory + "/" + f,index_col=0,skiprows=[3], encoding="utf-8")
		#print(data_xls[0:-1])
		#print(data_xls.count())
		#print(data_xls.tail())
		#print(data_xls.head())
		#label=data_xls.iloc[:,0]
		#print(" ")
		#print(" ")
		#print(" ")
		#print(label[:0])
		print("check up:["+filenames+"] is ok")
		return 0

#导出c++头文件
#导出php头文件
import struct
def xlsx_save(filenames):
		data_xls = pd.read_excel(gXlsxDirectory + "/" + filenames,index_col=0,skiprows=[3],encoding="utf-8")
		#获取记录数
		allvalues = len(data_xls.index)
		fulltypetible= '			{"'+ data_xls.index.name+'",{INT_FD, &'+ data_xls.index.name+'}},\n'
		fulltype= '	INT32 '+ data_xls.index.name+' = 0;            //'+ data_xls.index[1]+'\n'
		#获取表头名字
		alltitlename = data_xls.columns;
		lens = len(alltitlename)
		
		#print(data_xls.index.name+":"+str(data_xls.index[0])+":"+str(data_xls.index[2]))data_xls.index.name
		headcsv=data_xls.index.name;
		valuecsvlast="";
		#内容输出

		

		for f in alltitlename:
				headcsv += ","+f;
		#print("headcsv:"+headcsv)
		for num in range(2,len(data_xls.index)):
				#print(str(num)+":"+str(data_xls.index[num]))
				valuecsv='';
				valuecsv += str(data_xls.index[num]);
				
				for f in alltitlename:
						valuecsv += ",";
						if data_xls.iloc[0][f]=="int" or data_xls.iloc[0][f]=="[int" or data_xls.iloc[0][f]=="int]":
								valuecsv += str((data_xls.iloc[num][f]));
						elif data_xls.iloc[0][f]=="float" or data_xls.iloc[0][f]=="[float" or data_xls.iloc[0][f]=="float]":
								valuecsv += str((data_xls.iloc[num][f]));
						else:
								#print("..."+str(data_xls.iloc[num][f]))
								looks = str(data_xls.iloc[num][f]);
								if looks.find("\n") != -1:
										looks=looks.replace('\n', '')
										data_xls.iloc[num][f] = str(looks);
										#print(str(looks));
								if looks !="nan":
										valuecsv += '"'+str(data_xls.iloc[num][f])+'"';
								
								
										
								
						#print("alltitlename:"+f+":"+data_xls.iloc[0][f]+":"+str(data_xls.iloc[num][f]))
				if valuecsvlast!="":
						valuecsvlast += "\n";
				valuecsvlast += valuecsv;
		
		filenamescsv = filenames.replace(".xlsx", ".csv")	
		#print(filenamescsv)
		#print("valuecsvlast:"+valuecsvlast)
		list_dec = [0xef, 0xbb, 0xbf]
		with open("csv/"+filenamescsv,"wb") as f:
				for x in list_dec:
						a = struct.pack('B', x)
						f.write(a)
		with open("csv/"+filenamescsv,"a+",encoding='utf-8') as f:
				f.write(headcsv)
				f.write("\n")
				f.write(valuecsvlast)
		with open("csv/"+filenamescsv,"a+",encoding='utf-8') as f:
				f.write("\n")
		isArray = 0;
		aIndex = 0;
		Word = "";
		fullEnum = "";
		
		#PHP
		phpValueCsv = '<?php\nreturn array(\n';
		phpHeadCsvName=[];
		phpHeadCsvType=[];
		for f in alltitlename:
				phpHeadCsvName.append(f);
				lens = lens-1
				#print(f+":"+data_xls.iloc[0][f]+":"+data_xls.iloc[1][f])
				if data_xls.iloc[0][f] == 'int':
						phpHeadCsvType.append(1);
						if isArray == 0:
							fulltypetible += '			{"'+ f+'",{INT_FD, &'+ f+'}}'
							fulltype += '	INT32 '+ f+' = 0;\t\t\t\t//'+ data_xls.iloc[1][f]+''
						else:
							fulltypetible += '			{"' + f + '",{INT_FD, &' + Word + '[' + str(aIndex) + ']' + '}}'
							aIndex += 1;
				elif data_xls.iloc[0][f] == 'float':
						phpHeadCsvType.append(1);
						if isArray == 0:
							fulltypetible += '			{"'+ f+'",{FLOAT_FD, &'+ f+'}}'
							fulltype += '	float '+ f+' = 0.0f;\t\t\t\t//'+ data_xls.iloc[1][f]+''
						else:
							fulltypetible += '			{"' + f + '",{FLOAT_FD, &' + Word + '[' + str(aIndex) + ']' + '}}'
							aIndex += 1;
				elif data_xls.iloc[0][f] == 'str':
						phpHeadCsvType.append(2);
						if isArray == 0:
							fulltypetible += '			{"'+ f+'",{TSTR_FD, &'+ f+'}}'
							fulltype += '	TStr '+ f+' = "";\t\t\t\t//'+ data_xls.iloc[1][f]+''
						else:
							fulltypetible += '			{"' + f + '",{TSTR_FD, &' + Word + '[' + str(aIndex) + ']' + '}}'
							aIndex += 1;
				elif data_xls.iloc[0][f].find("[") != -1:
						if isArray != 0:
							break;

						ewwr = "";
						if data_xls.iloc[0][f].find("int") != -1:
							ewwr = "INT_FD";
							phpHeadCsvType.append(31);
						elif data_xls.iloc[0][f].find("float") != -1:
							ewwr = "FLOAT_FD";
							phpHeadCsvType.append(31);
						elif data_xls.iloc[0][f].find("str") != -1:
							ewwr = "TSTR_FD";
							phpHeadCsvType.append(32);
						else:
							print("ERROR filename:[" + str(filenames) + "] array error");
							return -1;
						
						wordLen = len(f) - 1;
						Word = f[0:wordLen];
						aIndex = 0;
						fulltypetible += '			{"'+f+'",{'+ewwr+', &'+ Word +'['+ str(aIndex) +']'+'}}'
						aIndex +=1;
						isArray = 1;
				elif data_xls.iloc[0][f].find("]") != -1:
						ewwr = "";
						eitr = "";
						if data_xls.iloc[0][f].find("int") != -1:
							ewwr = "INT_FD";
							eitr = "INT32";
							phpHeadCsvType.append(-31);
						elif data_xls.iloc[0][f].find("float") != -1:
							ewwr = "FLOAT_FD";
							eitr = "float";
							phpHeadCsvType.append(-31);
						elif data_xls.iloc[0][f].find("str") != -1:
							ewwr = "TSTR_FD";
							eitr = "TStr";
							phpHeadCsvType.append(-32);
						else:
							print("ERROR filename:[" + str(filenames) + "] array error");
							return -1;
					
						fulltypetible += '			{"'+f+'",{'+ewwr+', &'+ Word +'['+str(aIndex) +']'+'}}'
						aIndex +=1;
						wEnum = Word.upper() + "_NUM"
						fulltype += '	' + eitr + ' ' + Word +'['+wEnum +']' +';\t\t\t\t//'+ data_xls.iloc[1][f]+''
						fullEnum += '		' + wEnum + ' = ' + str(aIndex) + ',\n'
						isArray = 0;
				if lens != 0 :
						fulltypetible += ',\n'
						if isArray == 0 :
							fulltype += '\n'
		
		#phpValueCsv = '<?php\nreturn array("';
		#phpHeadCsvName=[];
		#phpHeadCsvType=[];
		#phpIsIndex = 0;
		#						if phpIsIndex == 0:
		#								phpHeadCsv += data_xls.iloc[num][f]+"=>[";
		#						
		#						if phpIsIndex != 0:
		#								phpHeadCsv += ",";
		#						phpHeadCsv += f+"=>"+str((data_xls.iloc[num][f]));
		#						
		#						phpIsIndex++;
		#						#101=>["ID"=>1,"name"=>"通用1"],
		#						print("..."+f+" "+data_xls.iloc[0][f]+":"+str((data_xls.iloc[num][f])));
		for num in range(2,len(data_xls.index)):
				isArray = 0;
				#if num >2:
				#		phpValueCsv+=",";
				#str(data_xls.index[2]))data_xls.index.name print(len(data_xls.index-2));
				phpValueCsv += str(data_xls.index[num])+'=>["'+str(data_xls.index.name)+'"=>'+str(data_xls.index[num]);
				for index in range(len(phpHeadCsvName)):
						phpValueCsv += ",";
						if phpHeadCsvType[index]==1:
								if isArray==1:
										phpValueCsv += str(data_xls.iloc[num][phpHeadCsvName[index]]);
								else:
										phpValueCsv += '"'+phpHeadCsvName[index]+'"=>'+str(data_xls.iloc[num][phpHeadCsvName[index]]);
						elif phpHeadCsvType[index]==2:
								if str(data_xls.iloc[num][phpHeadCsvName[index]]) == 'nan':
										if isArray==1:
												phpValueCsv += '""';
										else:
												phpValueCsv += '"'+phpHeadCsvName[index]+'"=>""';
								else:
										if isArray==1:
												phpValueCsv += '"'+str(data_xls.iloc[num][phpHeadCsvName[index]])+'"';
										else:
												phpValueCsv += '"'+phpHeadCsvName[index]+'"=>"'+str(data_xls.iloc[num][phpHeadCsvName[index]])+'"';
						elif phpHeadCsvType[index]>30:
								isArray = 1;
								names = phpHeadCsvName[index][0:len(phpHeadCsvName[index])-1]
								phpValueCsv +='"'+names+'"=>array(';
								if phpHeadCsvType[index]==31:
										phpValueCsv += str(data_xls.iloc[num][phpHeadCsvName[index]]);
								elif phpHeadCsvType[index]==32:
										if str(data_xls.iloc[num][phpHeadCsvName[index]]) == 'nan':
												phpValueCsv += '""';
										else:
												phpValueCsv += '"'+str(data_xls.iloc[num][phpHeadCsvName[index]])+'"';
						elif phpHeadCsvType[index]<-30:
								if phpHeadCsvType[index]==-31:
										phpValueCsv += str(data_xls.iloc[num][phpHeadCsvName[index]]);
								elif phpHeadCsvType[index]==-32:
										if str(data_xls.iloc[num][phpHeadCsvName[index]]) == 'nan':
												phpValueCsv += '""';
										else:
												phpValueCsv += '"'+str(data_xls.iloc[num][phpHeadCsvName[index]])+'"';
								isArray = 0;
								phpValueCsv += ")";
						#if phpHeadCsvType[index]==3:
								#phpValueCsv += phpHeadCsvName[index]+"=>"+str(data_xls.iloc[num][f]);
				phpValueCsv += "],\n";
		phpValueCsv += ");\n?>";

		filenamesphp = filenames.replace(".xlsx", ".csv.php")	
		with open("php/"+filenamesphp,"w",encoding='utf-8') as f:
				f.write(phpValueCsv)
				


		if isArray != 0:
			print("ERROR array");
			return -1;
		filenames = filenames.replace(".xlsx", "")	
		with open("Config.h","a+",encoding='utf-8') as f:
				f.write('struct '+filenames+'T : ConfigBaseT\n')
				f.write('{\n')
				f.write('	virtual ~'+filenames+'T()\n')	
				f.write('	{\n')
				f.write('	}\n')
				f.write('	'+filenames+'T()\n')	
				f.write('	{\n')
				f.write('		FileName = "'+filenames+'.csv";\n')
				f.write('		_kf =\n')
				f.write('		{\n')
				f.write(''+fulltypetible+'\n')
				f.write('		};\n')
				f.write('	}\n')
				f.write('	virtual '+filenames+'T* create()\n')
				f.write('	{\n')				
				f.write('		return new '+filenames+'T();\n')
				f.write('	}\n')
				f.write('	enum\n')
				f.write('	{\n')				
				f.write(''+fullEnum)
				f.write('	};\n')
				f.write(''+fulltype+'\n')
				f.write('};\n')
				f.write('CreateCsvClass('+filenames+');\n\n')
		return 0
		


def getExcel(file_dir):
    L=[]
    for root, dirs, files in os.walk(file_dir):
        for file in files:
            if os.path.splitext(file)[1] == '.xlsx':
                L.append(file)
    return L

def xlsx_to_csv_pd():
    xlsxFiles = getExcel(gXlsxDirectory)
    list_dec = [0xef, 0xbb, 0xbf]
    with open("Config.h","wb") as f:
    		for x in list_dec:
    				a = struct.pack('B', x)
    				f.write(a)
    with open("Config.h","a+",encoding='utf-8') as f:
    		f.write('#ifndef __TABLE_CONFIG_H\n')
    		f.write('#define __TABLE_CONFIG_H\n')	
    		f.write('#include "BaseConfigEx.h"\n')				
    for f in xlsxFiles:
    		if f == 'Config.h':
    				continue;
    		if f.find("~$")!=-1:
    				continue;
    		if xlsx_check(f) !=0:
    				continue;
    		xlsx_save(f);
    		#print("converting "+f)
    		#data_xls = pd.read_excel(gXlsxDirectory + "/" + f,index_col=0,skiprows=[1,2,3], encoding="gb2312")
				#print("converting "+data_xls[0])
    		#data_xls.to_csv(gCsvDirectory + "/" + f.replace(".xlsx", ".csv"), encoding="gb2312")
    		#自己书写保存转化格式
    		#break
    		
    with open(  "Config.h","a+",encoding='utf-8') as f:
    		f.write('#endif')

if __name__ == '__main__':
    xlsx_to_csv_pd()
    print("finished")
    os.system('pause')


