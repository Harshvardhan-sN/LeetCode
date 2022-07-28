class Solution {
    fun String.Sort() = String(toCharArray().apply{ sort() })
    fun isAnagram(s: String, t: String): Boolean {
        return t.Sort()==s.Sort()
    }
}