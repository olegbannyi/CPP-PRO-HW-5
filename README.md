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
Final balance: 78630.64
Total transactions: 920
Total transaction amount: 177294.93
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
Final balance: 85745.60
Total transactions: 1000
Total transaction amount: 188973.59
All cashiers completed work safely!
```
Transaction records are saved in log files:
```
build/safe/cachier-{1..5}.log
```
