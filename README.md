# CPP PRO: Home Work \#5

## Build and run

### Thread unsafe version

Build and run thread unsafe version

```bash
$ make all-unsafe
```

### Thread safe version

Build and run thread safe version

```bash
$ make all-safe
```

## Input parameters

```
Initial account balance: 1000.00
Number of cachiers: 5
Number of tranaction per cachier: 100
Random deposit amount: 50.00 - 500.00
Random withdraw amount: 10.00 - 200.00
```

## Example of results

### Thread unsafe version

Console output:
```
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 42006.57
Total transactions: 484
Total transaction amount: 94906.65
All cashiers completed work unsafely!
```
Transaction records are saved in log files:
```
build/unsafe/cachier-{1..5}.log
```

### Thread safe version

Console output:
```
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 42629.91
Total transactions: 500
Total transaction amount: 94975.94
All cashiers completed work safely!
```

Transaction records are saved in log files:
```
build/safe/cachier-{1..5}.log
```

## Reference mode
To verify app correctness, run it in reference mode. Deposit and withdraw always have constant value: 100 \
As a result:
 - initial balance should be equal to final balance (1000.00)
 - the result should be equal to the product of the number of transactions and their value \
Run in reference mode

### Thread unsafe version
```bash
$ make all-unsafe-ref
```
or compiled app
```bash
$ ./build/unsafe/banking.exe --ref
```
Console output:
```
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 491
Total transaction amount: 49100.00
All cashiers completed work unsafely!
```

### Thread safe version
```bash
$ make all-safe-ref
```
or compiled app
```bash
$ ./build/safe/banking.exe --ref
```
Console output:
```
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 500
Total transaction amount: 50000.00
All cashiers completed work safely!
```
