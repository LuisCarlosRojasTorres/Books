## Fact
- Facts are tests which are always true. They test invariant conditions


``` cs

[Fact]
public void PassingTest()
{
    Assert.Equal(4, Add(2, 2));
}

[Fact]
public void FailingTest()
{
    Assert.Equal(5, Add(2, 2));
}

int Add(int x, int y)
{
    return x + y;
}

[Fact] 
public void ShouldAddDoubleValues() 
{ 
    var sut = new Calculator(); 

    double result = sut.AddDoubles(1.1, 2.2); 

    Assert.Equal(3.3, result, precision: 1); 
}
```

## Theories
- Theories are tests which are only true for a particular set of data


``` cs
public class ParameterizedTests { 

    public bool IsOddNumber(int number) { 
        return number % 2 != 0; 
    } 

    [Theory]
    [InlineData(3)]
    [InlineData(5)]
    [InlineData(6)]
    public void MyFirstTheory(int value)
    {
        Assert.True(IsOdd(value));
    }

    [Theory] 
    [InlineData(5, 1, 3, 9)] 
    [InlineData(7, 1, 5, 3)] 
    public void AllNumbers_AreOdd_WithInlineData(int a, int b, int c, int d) { 

        Assert.True(IsOddNumber(a)); 

        Assert.True(IsOddNumber(b)); 

        Assert.True(IsOddNumber(c)); 

        Assert.True(IsOddNumber(d)); 
    }
}
```

# References

- [XUnit – Part 1: xUnit Packages and Writing Your First Unit Test](https://hamidmosalla.com/2020/01/05/xunit-part-1-xunit-packages-and-writing-your-first-unit-test/)  
- [XUnit – Part 2: Value and Type Based Assertions in xUnit](https://hamidmosalla.com/2020/01/12/xunit-part-2-value-and-type-based-assertions-in-xunit/)  
- [XUnit – Part 3: Action Based Assertions Assert.Raises and Assert.Throws](https://hamidmosalla.com/2020/01/20/xunit-part-3-action-based-assertions-assert-raises-and-assert-throws/)  
- [XUnit – Part 4: Parallelism and Custom Test Collections](https://hamidmosalla.com/2020/01/26/xunit-part-4-parallelism-and-custom-test-collections/)  
- [XUnit – Part 5: Share Test Context With IClassFixture and ICollectionFixture](https://hamidmosalla.com/2020/02/02/xunit-part-5-share-test-context-with-iclassfixture-and-icollectionfixture/)  
- [XUnit – Part 6: Testing The Database with xUnit Custom Attributes](https://hamidmosalla.com/2020/02/16/xunit-part-6-testing-the-database-with-xunit-custom-attributes/)  
- [XUnit – Part 7: Categorizing Tests with xUnit Trait](https://hamidmosalla.com/2020/03/01/xunit-part-7-categorizing-tests-with-xunit-trait/)  
- [XUnit – Part 8: Using TheoryData Instead of MemberData and ClassData](https://hamidmosalla.com/2020/04/05/xunit-part-8-using-theorydata-instead-of-memberdata-and-classdata/)  
- [Integration Test In Asp.Net Core 6 Using SqlServer Image and TestContainers](https://hamidmosalla.com/2022/09/10/integration-test-in-asp-net-core-6-using-sqlserver-image-and-testcontainers/)  
- [Unit Test section](https://hamidmosalla.com/category/unit-test/)