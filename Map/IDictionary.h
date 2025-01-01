#ifndef S3_LABORATORY_WORK_2_IDICTIONARY_H
#define S3_LABORATORY_WORK_2_IDICTIONARY_H
template<typename TKey, typename TElement>
class IDictionary {
public:
    virtual int GetCount() const = 0;

    virtual int GetCapacity() const = 0;

    virtual TElement Get(const TKey& key) const = 0;

    virtual bool ContainsKey(const TKey& key) const = 0;

    virtual void Add(const TKey& key, const TElement& element) = 0;

    virtual void Remove(const TKey& key) = 0;
};
#endif //S3_LABORATORY_WORK_2_IDICTIONARY_H
