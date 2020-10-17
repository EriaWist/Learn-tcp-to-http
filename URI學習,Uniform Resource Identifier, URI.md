# URI學習,Uniform Resource Identifier, URI
### [參考連結](https://notfalse.net/36/http-uri)


>## URI和URL的區別，URN又是什麼 :
>>* URI是以一種抽象的，高層次概念定義統一資源標識，而URL和URN則是具體的資源標識的方式。 URL和URN都是一種URI。 籠統地說，每個URL 都是URI，但不一定每個URI 都是URL。 這是因為URI 還包括一個子類，即統一資源名稱(URN)，它命名資源但不指定如何定位資源。
>>* 簡單來說URI就是抽象規定需要什麼
>>* Http裡其實是用URI只是大家都講URL(網址) `ex 指定了以「urn:」來加入http:、ftp:`
>>```
>>
>>統一資源定位符的標準格式如下：
  >>[協定類型]://[伺服器位址]:[埠號]/[資源層級UNIX檔案路徑][檔名]?[查詢]#[片段ID]
>>
>>統一資源定位符的完整格式如下：
  >>[協定類型]://[存取資源需要的憑證資訊]@[伺服器位址]:[埠號]/[資源層級UNIX檔案路徑][檔名]?[查詢]#[片段ID]
>>```
>>[上述連結](https://zh.wikipedia.org/wiki/%E7%BB%9F%E4%B8%80%E8%B5%84%E6%BA%90%E5%AE%9A%E4%BD%8D%E7%AC%A6)
>>
>>> 小知識:`冒號 (:) 唸作 colon [ˋkolən]，斜線 (/) 唸作 slash [slæʃ]，
點 (.) 唸作 dot [dɑt]，井號 (#) 唸作 hash [hæʃ]。`
>>>
>>>問號後面`?age=24&gender=female
代表的可能是，我想在這個網站 (如果有支援)尋找:
『年紀 24 且 性別是女性 』。
`
>>>保留字`「@」、「:」、「/」、「?」、「%」、「=」、「 」(空白) 例如: 「:」表示為 「%3A」這是 URI 規範中的 百分比編碼 (Percent-Encoding)，也就是俗稱的 URI (URL) 編碼。`
>>>
>>> 井字號#是由 Client 端 (通常為瀏覽器) 處理的部分，並 不會傳遞給 Server !
>>>
>>> 一個經典範例 — Google 搜尋:`https://www.google.com.tw/?gws_rd=ssl#q=搜尋內容`
>>>
>>>送出的內容其實為:`https://www.google.com.tw/search?q=搜尋內容&.....`

