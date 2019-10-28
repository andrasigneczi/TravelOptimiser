package HelloWorld;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.JavascriptExecutor;

import java.util.ArrayList;
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
        Thread.sleep(2000);  // Just to be sure! May crash occur wothout this sleep.

        System.out.println("Api version: " + getApiVersion(driver));

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
        Thread.sleep(2000);

        value0.click();
        Thread.sleep(2000);

        WebElement searchButton = driver.findElement(By.xpath( "//*[@id=\"flight-search\"]/div/div/div[2]/form/div[3]/button" ));
        searchButton.click();
        // the wait.until doesn't work here, it's a complex page, and slow with the booking at the same time
        Thread.sleep(20000);

        // switch to the first page
        ArrayList tabs = new ArrayList (driver.getWindowHandles());
        driver.switchTo().window(tabs.get(0).toString());
        Thread.sleep(3000);

        // closing the current page
        driver.close();
        Thread.sleep(3000);

        driver.quit();
    }
};
