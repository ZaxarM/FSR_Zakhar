
#ifndef EXCEPT_H
#define EXCEPT_H

enum ErrCode { FILE_NOT_OPEN, PARSE_ERROR };

class Except {
    ErrCode err_no;
    const char* description;

public:
    Except(ErrCode code, const char* desc);
    int get_err() const;
    void print() const;
};

#endif
