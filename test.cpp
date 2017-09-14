#if __cplusplus > 201100L
#include <cstdint>
#include <cstdio>
#else
#include <stdint.h>
#include <stdio.h>
#endif

#include <string>
#include <memory>

#include <stdarg.h>

#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>

#include <Mail.h>

using namespace std;

static boost::shared_ptr<string> seal_escape_string_lower(const string &aFrom)
{
    register size_t i;
    boost::shared_ptr<string> sEscaped(new (nothrow) string);

    sEscaped->reserve(aFrom.size() * 2);

    for (i = 0; i < aFrom.size(); i++)
    {
        switch (aFrom[i])
        {
            case '\'':
                *sEscaped += "''";
                break;

            default:
                *sEscaped += ::tolower(aFrom[i]);
        }
    }

    return sEscaped;
}

static boost::shared_ptr<string> seal_escape_string(const string &aFrom)
{
    register size_t i;
    boost::shared_ptr<string> sEscaped(new (nothrow) string);

    for (i = 0; i < aFrom.size(); i++)
    {
        switch (aFrom[i])
        {
            case '\'':
                *sEscaped += "''";
                break;

            default:
                *sEscaped += aFrom[i];
        }
    }

    return sEscaped;
}

static string make_format_str(const char *aFormat, ...) __attribute__ ((format (printf, 1, 2)));;

static string make_format_str(const char *aFormat, ...)
{
    int32_t  sLen;
    va_list  sAp;

    va_start(sAp, aFormat);
#if __cplusplus > 201100L
    sLen = vsnprintf(nullptr, 0, aFormat, sAp);
#else
    sLen = vsnprintf(NULL, 0, aFormat, sAp);
#endif
    va_end(sAp);

#if __cplusplus > 201100L
    unique_ptr<char[]> sBuffer(new char[sLen + 1]);

    va_start(sAp, aFormat);
    (void)vsnprintf(sBuffer.get(), sLen + 1, aFormat, sAp);
    va_end(sAp);

    return string(sBuffer.get(), sLen);
#else
    char *sBuffer = (char *)malloc(sLen + 1);
    va_start(sAp, aFormat);
    (void)vsnprintf(sBuffer, sLen + 1, aFormat, sAp);
    va_end(sAp);
    std::string sRet(sBuffer, sLen);
    free(sBuffer);
    return sRet;
#endif

}

static int32_t makeFractionForFirstLocatedAt(int64_t aMailSn)
{
    return (aMailSn % 100000);
}

#define QUERY_MAILS_INSERT \
    "/*! M#078 */ "\
    "INSERT INTO Mails (" \
        "Priorityem, " \
        "MailSn, FirstLocatedAt, ReplyTo, MimeId, " \
        "Pop3IconEm, ReceivedAt, SubjectAttr, FolderSn, ThreadId, OpenedAt, HeaderSize, " \
        "Subject, LastLocatedAt, ThreadOrderedAt, CharsetConversion, AttachCount, InlineCount, Bcc, " \
        "Cc, TextBodySn, HtmlBodySn, MessageId, PersonalDomainEmail, HeaderTo, `Size`, " \
        "StatusModifiedAt, HeaderFrom, SentAt, Flag, SeenfLag, " \
        "ClassificationCategory, ClassificationSubCategory, ClassificationReserved1, ClassificationReserved2, " \
        "SpamReason, SpamRuleNumber, NaverWorksEmailSn, Color, " \
        "FromAddr) " \
    " VALUES ("       \
        "%ld, " \
        "%ld,  %ld.%05d, '%s', '%s', " \
        "%ld,  %ld, '%s',  %d, '%s',  %ld,  %ld, " \
        "'%s', %ld,  %ld, '%s',  %ld,  %ld, '%s', " \
        "'%s', %ld,  %ld, '%s', '%s', '%s',  %ld, " \
        "%ld, '%s',  %ld,  %ld,  %ld, " \
        "%d, %d, %d, %d, " \
        "%d, %d, %d, %d, " \
        "'%s')"

string makeInsertMailQueryBoostFormat(const MailInfo &aMail)
{
    boost::format fmt(QUERY_MAILS_INSERT);

    fmt % aMail.getPriorityEm()
        % aMail.getMailSn()
        % aMail.getFirstLocatedAt()
        % makeFractionForFirstLocatedAt(aMail.getMailSn());

    fmt % seal_escape_string(aMail.getReplyTo())->c_str()
        % aMail.getMimeId().c_str()
        % aMail.getPop3IconEm()
        % aMail.getReceivedAt();

    fmt % aMail.getSubjectAttr().c_str()
        % aMail.getFolderSn()
        % seal_escape_string(aMail.getThreadId())->c_str()
        % aMail.getOpenedAt();

    fmt % aMail.getHeaderSize()
        % seal_escape_string(aMail.getSubject())->c_str()
        % aMail.getLastLocatedAt()
        % aMail.getThreadOrderedAt();

    fmt % aMail.getCharsetConversion().c_str()
        % aMail.getAttachCount()
        % aMail.getInlineCount()
        % seal_escape_string(aMail.getBcc())->c_str();

    fmt % seal_escape_string(aMail.getCc())->c_str()
        % aMail.getTextBodySn()
        % aMail.getHtmlBodySn()
        % seal_escape_string(aMail.getMessageId())->c_str();

    fmt % seal_escape_string(aMail.getPersonalDomainEmail())->c_str()
        % seal_escape_string(aMail.getHeaderTo())->c_str()
        % aMail.getSize()
        % aMail.getStatusModifiedAt();

    fmt % seal_escape_string(aMail.getHeaderFrom())->c_str()
        % aMail.getSentAt()
        % aMail.getFlag()
        % aMail.getSeenFlag();

    fmt % aMail.getCategory()
        % aMail.getSubCategory()
        % aMail.getExtCategory1()
        % aMail.getExtCategory2();

    fmt % aMail.getSpamReason()
        % aMail.getSpamRuleNumber()
        % aMail.getNaverWorksEmailSn()
        % aMail.getColor();

    fmt % seal_escape_string_lower(aMail.getHeaderFrom().c_str())->c_str();

    return fmt.str();
}

string makeInsertMailQueryPrintf(const MailInfo &aMail)
{
    return make_format_str(QUERY_MAILS_INSERT,
                           aMail.getPriorityEm(),
                           aMail.getMailSn(),
                           aMail.getFirstLocatedAt(),
                           makeFractionForFirstLocatedAt(aMail.getMailSn()),

                           seal_escape_string(aMail.getReplyTo())->c_str(),
                           aMail.getMimeId().c_str(),
                           aMail.getPop3IconEm(),
                           aMail.getReceivedAt(),

                           aMail.getSubjectAttr().c_str(),
                           aMail.getFolderSn(),
                           seal_escape_string(aMail.getThreadId())->c_str(),
                           aMail.getOpenedAt(),

                           aMail.getHeaderSize(),
                           seal_escape_string(aMail.getSubject())->c_str(),
                           aMail.getLastLocatedAt(),
                           aMail.getThreadOrderedAt(),

                           aMail.getCharsetConversion().c_str(),
                           aMail.getAttachCount(),
                           aMail.getInlineCount(),
                           seal_escape_string(aMail.getBcc())->c_str(),

                           seal_escape_string(aMail.getCc())->c_str(),
                           aMail.getTextBodySn(),
                           aMail.getHtmlBodySn(),
                           seal_escape_string(aMail.getMessageId())->c_str(),

                           seal_escape_string(aMail.getPersonalDomainEmail())->c_str(),
                           seal_escape_string(aMail.getHeaderTo())->c_str(),
                           aMail.getSize(),
                           aMail.getStatusModifiedAt(),

                           seal_escape_string(aMail.getHeaderFrom())->c_str(),
                           aMail.getSentAt(),
                           aMail.getFlag(),
                           aMail.getSeenFlag(),

                           aMail.getCategory(),
                           aMail.getSubCategory(),
                           aMail.getExtCategory1(),
                           aMail.getExtCategory2(),

                           aMail.getSpamReason(),
                           aMail.getSpamRuleNumber(),
                           aMail.getNaverWorksEmailSn(),
                           aMail.getColor(),

                           seal_escape_string_lower(aMail.getHeaderFrom().c_str())->c_str());
}

typedef string QueryMakerFunc(const MailInfo &);
typedef void InsertFunc(vector<string> *, const MailInfo &, QueryMakerFunc *);

static void printUsageAndExit(void)
{
    fprintf(stderr, "Usage: test LOOPCNT FUNC(printf/boost) EMPLACEPUSH(emplace/push) COPYMOVE(copy/move)\n");
    exit(1);
}

#if __cplusplus > 201100L
static void EmplaceCopy(vector<string> *aVector,
                        const MailInfo &aMail,
                        QueryMakerFunc *aQueryMaker)
{
    string sQuery(aQueryMaker(aMail));

    sQuery = sQuery + "1";

    aVector->emplace_back(sQuery);
}

static void EmplaceMove(vector<string> *aVector,
                        const MailInfo &aMail,
                        QueryMakerFunc *aQueryMaker)
{
    aVector->emplace_back(aQueryMaker(aMail) + "1");
}

static void PushMove(vector<string> *aVector,
                     const MailInfo &aMail,
                     QueryMakerFunc *aQueryMaker)
{
    aVector->push_back(aQueryMaker(aMail) + "1");
}
#endif

static void PushCopy(vector<string> *aVector,
                     const MailInfo &aMail,
                     QueryMakerFunc *aQueryMaker)
{
    string sQuery(aQueryMaker(aMail));

    sQuery = sQuery + "1";

    aVector->push_back(sQuery);
}

int32_t main(int32_t argc, char *argv[])
{
    MailInfo sMail;

    sMail.setReplyTo("shawn.yh.kim@worksmobile.com");
    sMail.setMimeId("123456789123456789.123456789.123456798");
    sMail.setSubjectAttr("Hey");
    sMail.setThreadId("<21f1d6879abdeb02cc8903883aed995@cvweditor01.nmdf.nhnsystem.com>");
    sMail.setSubject("RE: [압수수색영장전달] 웍스모바일 정보 제공 요청의 압수수색영장 전달드립니다.");
    sMail.setCharsetConversion("utf-8");
    sMail.setBcc("shawn.yh.kim@worksmobile.com");
    sMail.setCc("shawn.yh.kim@worksmobile.com");
    sMail.setMessageId("<ec3e40f5f415e76157d2e3f64acfa79@cvweditor01.nmdf.nhnsystem.com>");
    sMail.setPersonalDomainEmail("shawn.yh.kim@worksmobile.com");
    sMail.setHeaderTo("shawn.yh.kim@worksmobile.com");
    sMail.setHeaderFrom("shawn.yh.kim@worksmobile.com");
    sMail.setPreview("안녕하세요. 한성숙입니다. 이미 보도된 것처럼, "
                     "과거 우리 회사가 비공식적인 경로를 통해 특정인들의 자녀에게 "
                     "혜택을 제공한 불미스러운 일들이 있었습니다. "
                     "직원 여러분들이 각자의 자리에서 투명하고 깨끗한 "
                     "서비스를 만들기 위해 쏟아온 노력을 ");

    if (argc != 5)
    {
        printUsageAndExit();
    }

    int32_t i = 0;

    int32_t sLoopCnt = strtol(argv[1], NULL, 10);

    QueryMakerFunc *sQueryMaker;
    string sPrintfBoost(argv[2]);

    if (sPrintfBoost == "printf")
    {
        sQueryMaker = makeInsertMailQueryPrintf;
    }
    else if (sPrintfBoost == "boost")
    {
        sQueryMaker = makeInsertMailQueryBoostFormat;
    }
    else
    {
        printUsageAndExit();
    }

    InsertFunc *sInserter;
    string sEmplacePush(argv[3]);
    string sCopyMove(argv[4]);

#if __cplusplus > 201100L
    if (sEmplacePush == "emplace")
    {
        if (sCopyMove == "copy")
        {
            sInserter = EmplaceCopy;
        }
        else if (sCopyMove == "move")
        {
            sInserter = EmplaceMove;
        }
        else
        {
            printUsageAndExit();
        }
    }
    else
    {
#endif
        if (sEmplacePush == "push")
        {
            if (sCopyMove == "copy")
            {
                sInserter = PushCopy;
            }
#if __cplusplus > 201100L
            else
            {
                if (sCopyMove == "move")
                {
                    sInserter = PushMove;
                }
#endif
                else
                {
                    printUsageAndExit();
                }
#if __cplusplus > 201100L
            }
#endif
        }
        else
        {
            printUsageAndExit();
        }

#if __cplusplus > 201100L
    }
#endif

    vector<string> sQueryVector;

    while (i++ < sLoopCnt)
    {
        sInserter(&sQueryVector, sMail, sQueryMaker);
    }

    printf("vector size = %zu\n", sQueryVector.size());

    return 0;
}
