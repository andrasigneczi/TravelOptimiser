package HelloWorld;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.JavascriptExecutor;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SeleniumHelloWorld {
    private static String getApiVersion(WebDriver driver) {
        String lContent = driver.getPageSource();
        Pattern reg = Pattern.compile( "https\\://be\\.wizzair\\.com/(\\d{1,2}\\.\\d{1,2}\\.\\d{1,2})/Api" );
        Matcher m = reg.matcher( lContent );
        String lApiVersion = "9.0.0";
        if( m.find() )	{ lApiVersion = m.group(1).toString().trim(); }
        return lApiVersion;
    }

    public static void main(String[] args) throws InterruptedException {
        System.setProperty("webdriver.chrome.driver", "/usr/bin/chromedriver");

        WebDriver driver = new ChromeDriver();
        driver.get("https://wizzair.com");

        WebDriverWait wait = new WebDriverWait(driver, 15);
        wait.until(webDriver -> ((JavascriptExecutor) driver).executeScript("return document.readyState").toString().equals("complete"));
        Thread.sleep(25000);  // Just to be sure! May crash occur without this sleep.

        //System.out.println("Api version: " + getApiVersion(driver));

        WebElement departureBox = driver.findElement(By.id("search-departure-station"));
        departureBox.click();
        Thread.sleep(1000);

        departureBox.sendKeys("Budapest");
        Thread.sleep(2000);

        WebElement value0 = driver.findElement(By.xpath( "//*[@id=\"flight-search\"]/div/div/div[2]/form/div[1]/fieldset/div[3]/div/div[3]/div[1]/label" ));
        value0.click();
        Thread.sleep(1000);

        WebElement arrivalBox = driver.findElement(By.id("search-arrival-station"));
        arrivalBox.click();
        Thread.sleep(1000);

        arrivalBox.sendKeys("Charleroi");
        Thread.sleep(4000);

        value0.click();
        Thread.sleep(20000);

        WebElement searchButton = driver.findElement(By.xpath( "//*[@id=\"flight-search\"]/div/div/div[2]/form/div[3]/button" ));
        searchButton.click();
        // the wait.until doesn't work here, it's a complex page, and slow with the booking at the same time
        Thread.sleep(10000);

        // switch to the first page
        //ArrayList tabs = new ArrayList (driver.getWindowHandles());
        //driver.switchTo().window(tabs.get(0).toString());
        Thread.sleep(3000);

        // closing the current page
        //driver.close();
        Thread.sleep(60000);

        try {
            //WebElement element = driver.findElement(By.xpath("//*[@id=\"outbound-fare-selector\"]/div[2]/div[2]/div/div/div[2]/div[2]/div[1]/span"));
            List<WebElement> divs = driver.findElements(By.cssSelector("#outbound-fare-selector > div:nth-child(2) > div.flight-select__flight-list > div > div > div.flight-select__flight__fare-buttons > div:nth-child(2) > div.fare-type-button__title > span"));
            for(WebElement div : divs) {
                 //System.out.println(i++);
                 System.out.println("Price: " + div.getText());
            }
            // List<WebElement> divs = driver.findElements(By.tagName("div"));
            // int i = 0;
            // for(WebElement div : divs) {
            //     //System.out.println(i++);
            //     if(div.getAttribute("data-test") == "fare-type-button-title") {
            //         System.out.println("Price: " + div.getText());
            //         break;
            //     }
            // }
        } catch(Exception e) {
            System.out.println("Exception");
        }

        driver.quit();
    }
};
