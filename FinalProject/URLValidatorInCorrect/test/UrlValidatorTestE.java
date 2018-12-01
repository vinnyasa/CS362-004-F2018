

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
       boolean result = true;
       UrlValidator valid = new UrlValidator(null, null, 0);

       ResultPair[] manualTests = {new ResultPair("://docs.google.com/",false),
       new ResultPair("https://docs.google.com/", true),
       new ResultPair("httt://docs.google.com/", false),
       new ResultPair("httphttps://docs.google.com/", false),
       new ResultPair("hhttp>//www.google.com", false),
       new ResultPair("http://.com/", false),
       new ResultPair("https://github.com", true),
       new ResultPair("http://178.128.190.13", true),
       new ResultPair("https://github.com.github.com//", false),
       new ResultPair("https://github.gggg", false),
       new ResultPair("http://1.1.0.3", false),
       new ResultPair("https://github.com:", false),
       new ResultPair("http://178.128.190.13:3000/", true),
       new ResultPair("https://github.com:-15", false),
       new ResultPair("https://github.com::..", false),
       new ResultPair("https://sourceforge.net/", false);
       new ResultPair("https://html.spec.whatwg.org/multipage/", true),
       new ResultPair("https://twitter.com///vinnyasa", false),
       new ResultPair("https://www.linkedin.com/in/_/vinnyasa/", false)
       };

       for(int testcase = 0; testcase < manualTests.length; testcase++) {
           result = valid.isValid(manualTests[testcase].item);
           if(result != manualTests[testcase].valid) {
               System.out.print("URL Doesn't Match valid: " + manualTests[testcase].item);
           }
           else {
               System.out.print("URL Matches Return Value: " + manualTests[testcase].item);
           }
       }
   }
   
   
   public void testYourFirstPartition()
   {
       boolean result = true;
       UrlValidator valid = new UrlValidator(null, null, 0);

       ResultPair[] schemePart = {new ResultPair("//oregonstate.edu/", false),
            new ResultPair("https://www.oneplus.com/6", false),
               new ResultPair("httt://docs.google.com/", false),
               new ResultPair("htpp://oregonstate.edu/", false),
               new ResultPair("http>//www.linkedin.com", false),
               new ResultPair("https//osu-cs.slack.com", false)
       };

       ResultPair[] authorityPart = {new ResultPair("http://.com/", false),
               new ResultPair("https://docs.microsoft.com", false),
               new ResultPair("http://178.128.190.13", false),
               new ResultPair("htpp://oregonstate.eeeeee", false),
               new ResultPair("http://oregonstate", false),
               new ResultPair("https://osu-cs.slack.com", false)
       };

       for(int testcase = 0; testcase < authorityPart.length; testcase++) {
           result = valid.isValidAuthority(authorityPart[testcase].item);
           if (result != authorityPart[testcase].valid) {
               System.out.print("URL Doesn't Match valid: " + authorityPart[testcase].item);
           }
           else {
               System.out.print("URL Matches Return Value: " + authorityPart[testcase].item);
           }
       }

       ResultPair[] portPart = {new ResultPair("https://github.com:", false),
               new ResultPair("http://178.128.190.13:3000/", true),
               new ResultPair("https://github.com:-15", false),
               new ResultPair("https://github.com::..", false)
       };
           for(int testcase = 0; testcase < portPart.length; testcase++) {
               result = valid.isValidAuthority(portPart[testcase].item);
               if (result != portPart[testcase].valid) {
                   System.out.print("URL Doesn't Match valid: " + portPart[testcase].item);
               } else {
                   System.out.print("URL Matches Return Value: " + portPart[testcase].item);
               }
           }

       ResultPair[] pathPart = {new ResultPair("https://sourceforge.net/", false),
               new ResultPair("https://html.spec.whatwg.org/multipage/", true),
               new ResultPair("https://twitter.com///vinnyasa", false),
               new ResultPair("https://www.linkedin.com/in/_/vinnyasa/", false)
       };
           for(int testcase = 0; testcase < pathPart.length; testcase++) {
               result = valid.isValidPath(pathPart[testcase].item);
               if (result != pathPart[testcase].valid) {
                   System.out.print("URL Doesn't Match valid: " + pathPart[testcase].item);
               } else {
                   System.out.print("URL Matches Return Value: " + pathPart[testcase].item);
               }
           }

       ResultPair[] queryPart = {new ResultPair("https://www.google.com/search?q=test+queries&oq=test+queries", false)
       };

       for(int testcase = 0; testcase < queryPart.length; testcase++) {
           result = valid.isValidQuery(queryPart[testcase].item);
           if (result != queryPart[testcase].valid) {
               System.out.print("URL Doesn't Match valid: " + queryPart[testcase].item);
           } else {
               System.out.print("URL Matches Return Value: " + queryPart[testcase].item);
           }
       }

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
