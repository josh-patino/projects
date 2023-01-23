#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;


typedef set<string> SetStr;
typedef map<string, SetStr*> MapStrSetStr;

class DBConn {// supposed to connect here to a DB
public:
	void beginTxn(){}
	void endTxn(){}
	void execSql(string& sql){}
};

class SimpleTxnLog{
public:
	SimpleTxnLog(){}
	~SimpleTxnLog(){purge();}
	
	void addTxn(const string& id, const string& sql){
		SetStr* pSet = log_[id]; //this creates an entry if the ID is null
		if (pSet == NULL) {
			pSet = new SetStr(); 
			log_[id] = pSet; 
		}
		pSet->insert(sql);
	}
	
	//enters the SQL statements to the db, one trans at a time
	void apply() {
		for(MapStrSetStr::iterator p = log_.begin(); p != log_.end(); ++p){
			conn_->beginTxn(); 
			
			for(SetStr::iterator pSql = p->second->begin(); pSql != p->second->end(); ++pSql){
				string s = *pSql; 
				conn_->execSql(s); 
				cout << "Executing SQL: " << s <<endl; 
			}
			conn_->endTxn();
			delete p->second;
		}
		log_.clear(); 
	}
	
	void purge() {
		for (MapStrSetStr::iterator p = log_.begin(); p != log_.end(); ++p) {
			delete p->second;
		}
		log_.clear();
	}
	
private:
	MapStrSetStr log_;
	DBConn* conn_;
};




int main(int argc, char *argv[]) {
	
}