class Solution(object):
    def calPoints(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """

        st = []

        for string in operations:

            if string == "+":
                top = st[-1]
                st.pop()
                newtop = top + st[-1]
                st.append(top)
                st.append(newtop)

            elif string == "C":
                st.pop()

            elif string == "D":
                topdouble = 2 * st[-1]
                st.append(topdouble)

            else:
                st.append(int(string))

        res = 0

        for num in st:
            res += num

        return res