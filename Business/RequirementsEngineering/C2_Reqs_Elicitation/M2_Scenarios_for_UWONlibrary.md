- Scenario 1: Normal behavior - Book available in his department
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a physics book so he logs into the UWON library site.
  2. He writes the book name in the search bar and clicks on the `SEARCH` button.
  3. A list of all the copies (in all the departments of UWON) of the the book requested are shown.
  4. Luis selects a copy (in the department where he studies) and clicks on the `LOAN` button.
  5. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button.
  6. Now he can get the book on Monday in the morning.
- Scenario 2: Normal behavior - Book not available in his department, but available in other.
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a physics book so he logs into the UWON library site.
  2. He writes the book name in the search bar and clicks on the `SEARCH` button.
  3. A list of all the copies (in all the departments of UWON) of the the book requested are shown.
  4. *The book is not available in the department where he studies*.
  5. Luis selects a copy (in the CIVIL ENGINEERING department where he do not study) and clicks on the `LOAN` button.
  5. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button.
  6. Now he can get the book on Monday in the morning.
- Scenario 3: Normal behavior - Journal available in his department
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a scientific publication so he logs into the UWON library site.
  2. He writes the DOI number in the search bar and clicks on the `SEARCH` button.
  3. A list of all the links (each link belong to one of the department libraries) where the article can be downloaded are shown.
  4. Luis selects a link (from the department where he studies) and clicks on the `DOWNLOAD` button.
  5. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button. The download starts
  6. Now he have the article as a PDF file.
- Scenario 4: Normal behavior - Journal available in other department
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a scientific publication so he logs into the UWON library site.
  2. He writes the DOI number in the search bar and clicks on the `SEARCH` button.
  3. A list of all the links (each link belong to one of the department libraries) where the article can be downloaded are shown.
  4. *The article is not available in the department where he studies*
  5. Luis selects a link (from the another department) and clicks on the `DOWNLOAD` button.
  6. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button. The download starts
  7. Now he have the article as a PDF file.
- Scenario 5: Normal behavior - Book is in another university library
  1. Saturday at 5am Luis wakes up and starts to study. He nows he is looking for a book for a personal project. so he logs into the UWON library site.
  2. He writes the the book name and clicks on the `SEARCH` button.
  3. A list of all the copies of the the book requested are shown.
  4. *The book is not available in any of the departments of the UWON university*, However is available in another university.
  6. Luis selects a copy (which belongs to another university where he do not study) and clicks on the `LOAN` button.
  7. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button.
  8. A message appears that the book can be send to the library of the department where he studies in 24 hours
  9. Now he can get the book on TUESDAY in the morning.

- Scenario 1: AbNormal behavior - Book name is misspelled.
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a physics book so he logs into the UWON library site.
  2. He does not remember the name of the book very well so he writes some words related to the book name in the search bar and clicks on the `SEARCH` button.
  3. A list of books with similar names appear.
  4. Luis selects the correct name of the book.
  5. A list of all the copies (in all the departments of UWON) of the the book requested are shown.
  6. Luis selects a copy (in the department where he studies) and clicks on the `LOAN` button.
  7. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button.
  8. Now he can get the book on Monday in the morning.
- Scenario 2: AbNormal behavior - Book name does not exist.
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a physics book so he logs into the UWON library site.
  2. He does not remember the name of the book very well so he writes some words related to the book name in the search bar and clicks on the `SEARCH` button.
  3. A list of books with similar names appear.
  4. *However the book that he is looking for does not appear*
  5. Luis selects a book with similar content.
  6. A list of all the copies (in all the departments of UWON) of the the book requested are shown.
  7. Luis selects a copy (in the department where he studies) and clicks on the `LOAN` button.
  8. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button.
  9. Now he can get the book on Monday in the morning.
- Scenario 3: AbNormal behavior - He reach its maximun number of books borrowed at same time.
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a physics book so he logs into the UWON library site.
  2. He writes the book name in the search bar and clicks on the `SEARCH` button.
  3. A list of all the copies (in all the departments of UWON) of the the book requested are shown.
  4. Luis selects a copy (in the department where he studies) and clicks on the `LOAN` button.
  5. *A warning message appear, he currently has reach the limit of books. He needs to return one book to get a copy*
  6. Luis changes his mind and close the site.
- Scenario 4: AbNormal behavior - DOI number does not exist.
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a scientific publication so he logs into the UWON library site.
  2. He writes the DOI number in the search bar and clicks on the `SEARCH` button.
  3. *The DOI number is incorrect and there is now article related to it*.
  4. Luis writes the title of the article. 
  5. A list of all the links (each link belong to one of the department libraries) where the article can be downloaded are shown.
  6. *Its DOI number was wrong however the title was correct*
  7. Luis selects a link (from the department where he studies) and clicks on the `DOWNLOAD` button.
  8. A Terms and Condition modal appears. Luis clicks on the `ACCEPT` button. The download starts
  9. Now he have the article as a PDF file.
- Scenario 5: AbNormal behavior - All books are taken. 
  1. Saturday at 5am Luis wakes up and starts to study. He nows he needs a physics book so he logs into the UWON library site.
  2. He writes the book name in the search bar and clicks on the `SEARCH` button.
  3. *No copies are available now, all are taken*
  4. Luis clicks on the `WAITING LIST` button to receive an email when a copy is available.