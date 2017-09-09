#include "SQLiteTest.h"
#include <iostream>

extern "C" {

#include "sqlite/sqlite3.h"

	static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
		int i;
		for (i = 0; i < argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}
		printf("\n");
		return 0;
	}

	void run() {
		sqlite3 *db;
		char *zErrMsg = 0;
		int rc;
		rc = sqlite3_open("test.db", &db);

		if (rc) {
			std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
			sqlite3_close(db);
			return;
		}

		rc = sqlite3_exec(db, "select * from Search", callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			std::cerr << "SQL error: " << zErrMsg << std::endl;
			sqlite3_free(zErrMsg);

		}
		sqlite3_close(db);
	}
}

void SQLiteTest::run() {
	::run();
}
