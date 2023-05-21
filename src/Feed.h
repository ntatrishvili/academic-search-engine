    #include"Entry.h"

    class Feed{
        std::string id;
        std::vector<Entry> entries;
    public:
        //all the constructors
        Feed();
        Feed(std::string _id);
        Feed(std::vector<Entry> _entries);
        Feed(std::string _id, std::vector<Entry> _entries);

        ~Feed(){
            // first delete every entry
            for (int i = 0; i < entries.size(); i++)
            {
                // delete* entries.at(i);
            }
            // then delete the 'entries' vector
            entries.clear();
        }
        //all the getters
        std::string getId();
        Entry getEntryById(std::string entryId);
        std::vector<Entry> getEntriesByAuthor(std::string AuthorName);
        std::vector<Entry> getEntriesByPublishDate(std::tm publishDate);
        std::vector<Entry> getEntriesByUpdateDate(std::tm updateDate);
        std::vector<Entry> getEntriesByTitle(std::string title);
        std::vector<Entry> getEntriesByPages(int commentPagesNum);

        //add
        void addEntry(const Entry& entry);
        void filterEntries();
        void sortEntries();
        void fillInfo(std::string address);

        //toString to output the feed in a human readable way 
        std::string toString();

    };