#include "template.hpp"

template <class T1>
ToFile<T1>::ToFile(){
	this->a=0;
}

template <class T1>
void ToFile<T1>::addElement(std::string n, T1 m){
	if(a>5)
		a=5;
	for(unsigned int i=0;i<this->a;i++){
		if(m>this->score[i]){
			for(unsigned int j=a-2;j>=i+1;j--){
				this->score[j]=this->score[j-1];
				this->name[j]=this->name[j-1];
			}
			this->score[i]=m;
			this->name[i]=n;
			break;
		}
	}
}

template <class T1>
void ToFile<T1>::write(){
	std::fstream file;
	file.open("score.txt", std::ios::out);
	if(this->a>5)
		this->a=5;
	if(file.good()){
		for(unsigned int i=0;i<this->a;i++){
			file<<this->name[i]<<"\n"<<this->score[i]<<"\n";
		}
	}
}

template <class T1>
void ToFile<T1>::read(){
	std::fstream file;
	file.open("score.txt", std::ios::in);
	if(file.good()){
		if(this->a>0)
			this->a=0;
		char line [256];
		while(file.getline(line, 256) && this->a<5 ){
			this->name[a].assign(line);//std::cout<<this->a<<" "<<this->name[a]<<" ";
			file.getline(line, 256);
			this->tmp0.assign(line);//std::cout<<" tmp: "<<this->tmp0<<" ";
			this->score[a]=toUInt(this->tmp0);//std::cout<<this->score[a]+1<<"\n";
			this->a++;
		}
	}
	else{
		this->a=0;
	}
}

template <class T1>
unsigned int ToFile<T1>::returnSize(){
	return this->a;
}

template <class T1>
std::string ToFile<T1>::returnName(unsigned int i){
	if(i>=this->a)
		return " ";
	else
		return this->name[i];
}

template <class T1>
T1 ToFile<T1>::returnScore(unsigned int i){
	if(i>=this->a)
		return 0;
	else
		return this->score[i];
}
