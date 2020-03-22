# 在python中复制一个新列表，操作不影响原列表的方法有：
# 1.使用切片      list2 = list1[:]
# 2.使用copy      list2 = list1.copy()
# 3.使用循环复制法 list2 = [for i in list1]
class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        ans = []
        products.sort()
        checklist = products[:]
        for i in range(len(searchWord)):
            tmp = []
            pattern = searchWord[:i+1]
            for s in checklist:
                if s.startswith(pattern):
                    tmp.append(s)
            tmp.sort()
            checklist = tmp[:]
            ans.append(tmp[:3])
        return ans