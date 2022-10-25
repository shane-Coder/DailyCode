class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String res="", ans="";
        for(String s:word1)
            res += s;
        for(String s:word2)
            ans += s;
        return res.equals(ans);
    }
}