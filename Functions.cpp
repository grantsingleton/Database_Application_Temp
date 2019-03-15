#include "Functions.h"


Database* populateDatabase()
{
	Database* db = new Database();
	
	/**********************************
	*       FILL BUSINESS TABLE       *
	***********************************/
	ifstream business_file;
	business_file.open("business.json");
	if (business_file.is_open())
	{
		// good to go
	}
	else
	{
		cout << "error: 'business.json' did not open" << endl;
		return db;
	}
	std::string line;
	const char* json_line;
	rapidjson::Document doc;

	Table* business_table = new Table( {"business_id", "name", "address", "city", "state", "postal_code", "stars", "review_count", "is_open", "categories" } );

	for (int i = 0; i < 1000; i++) // get 1000 lines 
	{
		getline(business_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);

		// Fill a record in the Table
		Record new_record;

		assert(doc.HasMember("business_id"));
		if (!doc["business_id"].IsNull())
		{
			new_record.addEntry(doc["business_id"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("name"));
		if (!doc["name"].IsNull())
		{
			new_record.addEntry(doc["name"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("address"));
		if (!doc["address"].IsNull())
		{
			new_record.addEntry(doc["address"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("city"));
		if (!doc["city"].IsNull())
		{
			new_record.addEntry(doc["city"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("state"));
		if (!doc["state"].IsNull())
		{
			new_record.addEntry(doc["state"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("postal_code"));
		if (!doc["postal_code"].IsNull())
		{
			new_record.addEntry(doc["postal_code"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("stars"));
		if (!doc["stars"].IsNull())
		{
			new_record.addEntry(to_string(doc["stars"].GetDouble()));
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("review_count"));
		if (!doc["review_count"].IsNull())
		{
			new_record.addEntry(to_string(doc["review_count"].GetInt()));
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("is_open"));
		if (!doc["is_open"].IsNull())
		{
			new_record.addEntry(to_string(doc["is_open"].GetInt()));
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("categories"));
		if (!doc["categories"].IsNull())
		{
			new_record.addEntry(doc["categories"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		// add record to Table
		business_table->insertRecord(new_record);
	}
	business_file.close();

	// add business table to database
	db->addTable(business_table, "Business");


	/**********************************
	*         FILL USER TABLE         *
	***********************************/
	ifstream user_file;
	user_file.open("user.json");
	if (user_file.is_open())
	{
		// good to go
	}
	else
	{
		cout << "error: 'user.json' did not open" << endl;
		return db;
	}

	Table* user_table = new Table({ "user_id", "name", "review_count", "yelping_since", "useful", "funny", "cool", "elite", "friends", "fans", "average_stars" });

	for (int i = 0; i < 1000; i++) // get 1000 lines 
	{
		getline(user_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);

		// Fill a record in the Table
		Record new_record;

		assert(doc.HasMember("user_id"));
		if (!doc["user_id"].IsNull())
		{
			new_record.addEntry(doc["user_id"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("name"));
		if (!doc["name"].IsNull())
		{
			new_record.addEntry(doc["name"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("review_count"));
		if (!doc["review_count"].IsNull())
		{
			new_record.addEntry( to_string (doc["review_count"].GetInt()) );
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("yelping_since"));
		if (!doc["yelping_since"].IsNull())
		{
			new_record.addEntry(doc["yelping_since"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("useful"));
		if (!doc["useful"].IsNull())
		{
			new_record.addEntry(to_string (doc["useful"].GetInt()) );
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("funny"));
		if (!doc["funny"].IsNull())
		{
			new_record.addEntry(to_string (doc["funny"].GetInt()) );
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("cool"));
		if (!doc["cool"].IsNull())
		{
			new_record.addEntry(to_string (doc["cool"].GetInt()) );
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("elite"));
		if (!doc["elite"].IsNull())
		{
			new_record.addEntry(doc["elite"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("friends"));
		if (!doc["friends"].IsNull())
		{
			new_record.addEntry(doc["friends"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("fans"));
		if (!doc["fans"].IsNull())
		{
			new_record.addEntry(to_string (doc["fans"].GetInt()) );
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("average_stars"));
		if (!doc["average_stars"].IsNull())
		{
			new_record.addEntry(to_string (doc["average_stars"].GetDouble()) );
		}
		else
		{
			new_record.addEntry("");
		}

		// add record to Table
		user_table->insertRecord(new_record);
	}
	user_file.close();

	// add user table to database
	db->addTable(user_table, "User");

	/**********************************
	*        FILL REVIEW TABLE        *
	***********************************/
	ifstream review_file;
	review_file.open("review.json");
	if (review_file.is_open())
	{
		// good to go
	}
	else
	{
		cout << "error: 'review.json' did not open" << endl;
		return db;
	}

	Table* review_table = new Table({ "review_id", "user_id", "business_id", "stars", "useful", "funny", "cool", "text", "date" }); 

	for (int i = 0; i < 1000; i++) // get 1000 lines 
	{
		getline(review_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);

		// Fill a record in the Table
		Record new_record;

		assert(doc.HasMember("review_id"));
		if (!doc["review_id"].IsNull())
		{
			new_record.addEntry(doc["review_id"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("user_id"));
		if (!doc["user_id"].IsNull())
		{
			new_record.addEntry(doc["user_id"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("business_id"));
		if (!doc["business_id"].IsNull())
		{
			new_record.addEntry(doc["business_id"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("stars"));
		if (!doc["stars"].IsNull())
		{
			new_record.addEntry(to_string(doc["stars"].GetDouble()));
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("useful"));
		if (!doc["useful"].IsNull())
		{
			new_record.addEntry(to_string(doc["useful"].GetInt()));
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("funny"));
		if (!doc["funny"].IsNull())
		{
			new_record.addEntry(to_string(doc["funny"].GetInt()));
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("cool"));
		if (!doc["cool"].IsNull())
		{
			new_record.addEntry(to_string(doc["cool"].GetInt()));
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("text"));
		if (!doc["text"].IsNull())
		{
			new_record.addEntry(doc["text"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("date"));
		if (!doc["date"].IsNull())
		{
			new_record.addEntry(doc["date"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		// add record to Table
		review_table->insertRecord(new_record);
	}
	review_file.close();

	// add review table to database
	db->addTable(review_table, "Review");


	/**********************************
	*       FILL CHECK IN TABLE       *
	***********************************/
	ifstream checkin_file;
	checkin_file.open("checkin.json");
	if (checkin_file.is_open())
	{
		// good to go
	}
	else
	{
		cout << "error: 'checkin.json' did not open" << endl;
		return db;
	}

	Table* checkin_table = new Table({ "business_id", "date" }); 

	for (int i = 0; i < 1000; i++) // get 1000 lines 
	{
		getline(checkin_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);

		// Fill a record in the Table
		Record new_record;

		assert(doc.HasMember("business_id"));
		if (!doc["business_id"].IsNull())
		{
			new_record.addEntry(doc["business_id"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		assert(doc.HasMember("date"));
		if (!doc["date"].IsNull())
		{
			new_record.addEntry(doc["date"].GetString());
		}
		else
		{
			new_record.addEntry("");
		}

		// add record to Table
		checkin_table->insertRecord(new_record);
	}
	checkin_file.close();

	// add checkin table to database
	db->addTable(checkin_table, "Checkin");

	return db;
}
