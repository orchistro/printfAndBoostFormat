/*
 * vim 설정
 * vim:ts=4:shiftwidth=4:et:cindent:fileencoding=utf-8:
 */

#pragma once

#include <string>

class MailInfo
{
private:
    int64_t     mPriorityEm;
    int64_t     mClassificationType;
    int64_t     mMailSn;
    int64_t     mFirstLocatedAt;
    std::string mReplyTo;
    std::string mMimeId;
    int64_t     mPop3IconEm;
    int64_t     mReceivedAt;
    std::string mSubjectAttr;
    int32_t     mFolderSn;
    std::string mThreadId;
    int64_t     mOpenedAt;
    int64_t     mHeaderSize;
    std::string mSubject;
    int64_t     mLastLocatedAt;
    int64_t     mThreadOrderedAt;
    std::string mCharsetConversion;
    int64_t     mAttachCount;
    int64_t     mInlineCount;
    std::string mBcc;
    std::string mCc;
    int64_t     mTextBodySn;
    int64_t     mHtmlBodySn;
    std::string mMessageId;
    std::string mPersonalDomainEmail;
    std::string mHeaderTo;
    int64_t     mSize;
    int64_t     mStatusModifiedAt;
    std::string mHeaderFrom;
    int64_t     mSentAt;
    int64_t     mFlag;
    int64_t     mSeenFlag;
    int32_t     mCategory;
    int32_t     mSubCategory;
    int32_t     mExtCategory1;
    int32_t     mExtCategory2;
    int32_t     mSpamReason;
    int32_t     mSpamRuleNumber;
    int16_t     mNaverWorksEmailSn;
    int32_t     mColor;
    std::string mPreview;
    int32_t     mExistPreview;

public:
    MailInfo() : mPriorityEm(0), mClassificationType(0), mFirstLocatedAt(0), mPop3IconEm(0), mReceivedAt(0), mOpenedAt(0), mHeaderSize(0), mLastLocatedAt(0), mThreadOrderedAt(0), mAttachCount(0), mInlineCount(0), mSize(0), mStatusModifiedAt(0), mSentAt(0), mFlag(0), mSeenFlag(0), mCategory(-1), mSubCategory(-1), mExtCategory1(-1), mExtCategory2(-1), mSpamReason(-1), mSpamRuleNumber(-1), mNaverWorksEmailSn(0), mColor(16777215), mExistPreview(0)
    {
    }

    static inline int64_t extractFirstDigitFromPriorityEm(int64_t aPriorityEm)
    {
        while (aPriorityEm >= 10) aPriorityEm = aPriorityEm / 10;
        return aPriorityEm;
    }

    int64_t getPriorityEm() const
    {
        return mPriorityEm;
    }
    int64_t getClassificationType() const
    {
        return mClassificationType;
    }
    int64_t getMailSn() const
    {
        return mMailSn;
    }
    int64_t getFirstLocatedAt() const
    {
        return mFirstLocatedAt;
    }
    const std::string &getReplyTo() const
    {
        return mReplyTo;
    }
    const std::string &getMimeId() const
    {
        return mMimeId;
    }
    int64_t getPop3IconEm() const
    {
        return mPop3IconEm;
    }
    int64_t getReceivedAt() const
    {
        return mReceivedAt;
    }
    const std::string &getSubjectAttr() const
    {
        return mSubjectAttr;
    }
    int32_t getFolderSn() const
    {
        return mFolderSn;
    }
    const std::string &getThreadId() const
    {
        return mThreadId;
    }
    int64_t getOpenedAt() const
    {
        return mOpenedAt;
    }
    int64_t getHeaderSize() const
    {
        return mHeaderSize;
    }
    const std::string &getSubject() const
    {
        return mSubject;
    }
    int64_t getLastLocatedAt() const
    {
        return mLastLocatedAt;
    }
    int64_t getThreadOrderedAt() const
    {
        return mThreadOrderedAt;
    }
    const std::string &getCharsetConversion() const
    {
        return mCharsetConversion;
    }
    int64_t getAttachCount() const
    {
        return mAttachCount;
    }
    int64_t getInlineCount() const
    {
        return mInlineCount;
    }
    const std::string &getBcc() const
    {
        return mBcc;
    }
    const std::string &getCc() const
    {
        return mCc;
    }
    int64_t getTextBodySn() const
    {
        return mTextBodySn;
    }
    int64_t getHtmlBodySn() const
    {
        return mHtmlBodySn;
    }
    const std::string &getMessageId() const
    {
        return mMessageId;
    }
    const std::string &getPersonalDomainEmail() const
    {
        return mPersonalDomainEmail;
    }
    const std::string &getHeaderTo() const
    {
        return mHeaderTo;
    }
    int64_t getSize() const
    {
        return mSize;
    }
    int64_t getStatusModifiedAt() const
    {
        return mStatusModifiedAt;
    }
    const std::string &getHeaderFrom() const
    {
        return mHeaderFrom;
    }
    int64_t getSentAt() const
    {
        return mSentAt;
    }
    int64_t getFlag() const
    {
        return mFlag;
    }
    int64_t getSeenFlag() const
    {
        return mSeenFlag;
    }
    int32_t getCategory() const
    {
        return mCategory;
    }
    int32_t getSubCategory() const
    {
        return mSubCategory;
    }
    int32_t getExtCategory1() const
    {
        return mExtCategory1;
    }
    int32_t getExtCategory2() const
    {
        return mExtCategory2;
    }
    int32_t getSpamReason() const
    {
        return mSpamReason;
    }
    int32_t getSpamRuleNumber() const
    {
        return mSpamRuleNumber;
    }
    int16_t getNaverWorksEmailSn() const
    {
        return mNaverWorksEmailSn;
    }
    int32_t getColor() const
    {
        return mColor;
    }
    const std::string &getPreview() const
    {
        return mPreview;
    }
    int32_t getExistPreview() const
    {
        return mExistPreview;
    }

    void setPriorityEm(int64_t priorityEm)
    {
        mPriorityEm = priorityEm;
    }
    void setClassificationType(int64_t classificationType)
    {
        mClassificationType = classificationType;
    }
    void setMailSn(int64_t mailSn)
    {
        mMailSn = mailSn;
    }
    void setFirstLocatedAt(int64_t firstLocatedAt)
    {
        mFirstLocatedAt = firstLocatedAt;
    }
    void setReplyTo(const std::string &replyTo)
    {
        mReplyTo = replyTo;
    }
    void setReplyTo(const char *replyTo)
    {
        mReplyTo = replyTo;
    }
    void setMimeId(const std::string &mimeId)
    {
        mMimeId = mimeId;
    }
    void setMimeId(const char *mimeId)
    {
        mMimeId = mimeId;
    }
    void setPop3IconEm(int64_t pop3IconEm)
    {
        mPop3IconEm = pop3IconEm;
    }
    void setReceivedAt(int64_t receivedAt)
    {
        mReceivedAt = receivedAt;
    }
    void setSubjectAttr(const std::string &subjectAttr)
    {
        mSubjectAttr = subjectAttr;
    }
    void setSubjectAttr(const char *subjectAttr)
    {
        mSubjectAttr = subjectAttr;
    }
    void setFolderSn(int32_t folderSn)
    {
        mFolderSn = folderSn;
    }
    void setThreadId(const std::string &threadId)
    {
        mThreadId = threadId;
    }
    void setThreadId(const char *threadId)
    {
        mThreadId = threadId;
    }
    void setOpenedAt(int64_t openedAt)
    {
        mOpenedAt = openedAt;
    }
    void setHeaderSize(int64_t headerSize)
    {
        mHeaderSize = headerSize;
    }
    void setSubject(const std::string &subject)
    {
        mSubject = subject;
    }
    void setSubject(const char *subject)
    {
        mSubject = subject;
    }
    void setLastLocatedAt(int64_t lastLocatedAt)
    {
        mLastLocatedAt = lastLocatedAt;
    }
    void setThreadOrderedAt(int64_t threadOrderedAt)
    {
        mThreadOrderedAt = threadOrderedAt;
    }
    void setCharsetConversion(const std::string &charsetConversion)
    {
        mCharsetConversion = charsetConversion;
    }
    void setCharsetConversion(const char *charsetConversion)
    {
        mCharsetConversion = charsetConversion;
    }
    void setAttachCount(int64_t attachCount)
    {
        mAttachCount = attachCount;
    }
    void setInlineCount(int64_t inlineCount)
    {
        mInlineCount = inlineCount;
    }
    void setBcc(const std::string &bcc)
    {
        mBcc = bcc;
    }
    void setBcc(const char *bcc)
    {
        mBcc = bcc;
    }
    void setCc(const std::string &cc)
    {
        mCc = cc;
    }
    void setCc(const char *cc)
    {
        mCc = cc;
    }
    void setTextBodySn(int64_t textBodySn)
    {
        mTextBodySn = textBodySn;
    }
    void setHtmlBodySn(int64_t htmlBodySn)
    {
        mHtmlBodySn = htmlBodySn;
    }
    void setMessageId(const std::string &messageId)
    {
        mMessageId = messageId;
    }
    void setMessageId(const char *messageId)
    {
        mMessageId = messageId;
    }
    void setPersonalDomainEmail(const std::string &personalDomainEmail)
    {
        mPersonalDomainEmail = personalDomainEmail;
    }
    void setPersonalDomainEmail(const char *personalDomainEmail)
    {
        mPersonalDomainEmail = personalDomainEmail;
    }
    void setHeaderTo(const std::string &headerTo)
    {
        mHeaderTo = headerTo;
    }
    void setHeaderTo(const char *headerTo)
    {
        mHeaderTo = headerTo;
    }
    void setSize(int64_t size)
    {
        mSize = size;
    }
    void setStatusModifiedAt(int64_t statusModifiedAt)
    {
        mStatusModifiedAt = statusModifiedAt;
    }
    void setHeaderFrom(const std::string &headerFrom)
    {
        mHeaderFrom = headerFrom;
    }
    void setHeaderFrom(const char *headerFrom)
    {
        mHeaderFrom = headerFrom;
    }
    void setSentAt(int64_t sentAt)
    {
        mSentAt = sentAt;
    }
    void setFlag(int64_t flag)
    {
        mFlag = flag;
    }
    void setSeenFlag(int64_t flag)
    {
        mSeenFlag = flag;
    }
    void setBitFlag(int64_t flag)
    {
        mFlag |= flag;
    }
    void unsetBitFlag(int64_t flag)
    {
        mFlag &= (~flag);
    }
    void setCategory(int32_t category)
    {
        mCategory = category;
    }
    void setSubCategory(int32_t subCategory)
    {
        mSubCategory = subCategory;
    }
    void setExtCategory1(int32_t extCategory1)
    {
        mExtCategory1 = extCategory1;
    }
    void setExtCategory2(int32_t extCategory2)
    {
        mExtCategory2 = extCategory2;
    }
    void setSpamReason(int32_t spamReason)
    {
        mSpamReason = spamReason;
    }
    void setSpamRuleNumber(int32_t spamRuleNumber)
    {
        mSpamRuleNumber = spamRuleNumber;
    }
    void setNaverWorksEmailSn(int16_t naverWorksEmailSn)
    {
        mNaverWorksEmailSn = naverWorksEmailSn;
    }
    void setColor(int32_t aColor)
    {
        mColor = aColor;
    }
#if __cplusplus > 201100L
    void setPreview(std::string &&preview)
    {
        mPreview = std::move(preview);
    }
#endif
    void setPreview(const std::string &preview)
    {
        mPreview = preview;
    }
    void setExistPreview(int32_t aExistPreview)
    {
        mExistPreview = aExistPreview;
    }
};
