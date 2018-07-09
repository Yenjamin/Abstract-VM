int	main(void)
{
	UserEntry entry;

	try
	{
		entry.checkErrorFlag(argc, argv);
		if (argc == 1)
			entry.readEntry();
		else if (argc >= 2)
			entry.readFile(argv[1]);
		else {
			throw UserEntry::WrongArgumentNumber();
		}

		try
		{
			Parser::ParseEntry(entry.getContent());
		}
		catch (std::logic_error &e)
		{
			std::cout << "Logic error occured: " << e.what() << std::endl;
			if (entry.getFlagError() == true)
				TestError(entry);
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error on start: " << e.what() << std::endl;
	}
	return (0);
}
