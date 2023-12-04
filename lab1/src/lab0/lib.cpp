#include "lib.h"

void СheckInt(string inStr)
{
    string  clean_string = "";
    const regex pattern("[^0-9]");
    clean_string = regex_replace(inStr, pattern, "");
    if (inStr.size() != clean_string.size()) {
        throw "erunda";
    }
}
int Cutter_Chocolate(int rows,int cols)
{
    int transition_to_gaps=1;
    int result = (rows*cols)-transition_to_gaps;
    return result;
}
int Try_to_calculate(string rows,string cols)
{
    int rows_int,cols_int;
    try {
        СheckInt(rows);
        СheckInt(cols);

        rows_int = atoi(rows.c_str());
        cols_int = atoi(cols.c_str());

        if (rows_int == 0 or cols_int == 0) {
            throw 0;
        }
        return Cutter_Chocolate(rows_int,cols_int);

    } catch (...) {
        return 0;
    }
}